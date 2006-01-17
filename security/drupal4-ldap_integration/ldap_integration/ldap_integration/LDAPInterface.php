<?php
// $Id: LDAPInterface.php,v 1.1.4.8 2005/11/03 20:15:32 pablobm Exp $

class LDAPInterface {
  
  function LDAPInterface() {
    $this->connection = null;
    $this->server = localhost;
    $this->port = 389;
    $this->secretKey = NULL;
    $this->useTLS = false;
  }

  var $connection;
  var $server;
  var $port;
  var $useTLS;
  
  // Setters & getters
  function setServer($server) { $this->server = $server; }
  function getServer() { return $this->server; }
  function setPort($port) { $this->port = $port; }
  function getPort() { return $this->port; }
  
  function setOption($option, $value) {
    if ($option == 'TLS') {
      $this->useTLS = $value;
    }
  }
  
  function getOption($option) {
    $ret = -1;
    
    if ($option == 'version') {
      ldap_get_option($this->connection, LDAP_OPT_PROTOCOL_VERSION, $ret);
    }
    
    return $ret;
  }
    
  function connect($dn = '', $pass = '') {
    $ret = FALSE;

    // If a connection already exists, it should be terminated
    $this->disconnect();
    
    if ($this->connectAndBind($dn, $pass)) {
      $ret = TRUE;
    }

    return $ret;
  }
  
  // Code contributed by allrite@drupal.org (http://allrite.net)
  // Patched (2005-09-06) by sfrancis@drupal.org
  // Patched (2005-10-29) by Perfect Stranger (@drupal.org)
  function connect_ADstyle($uattr = '', $name = '', $base_dn = '', $pass = '') {
    global $ldap;
    
    // If a connection already exists, it should be terminated
    $this->disconnect();
    $this->establishConnection();

    ob_start();    
    $anon_bind = @ldap_bind($this->connection, LDAP_READER_USER_DN, LDAP_READER_USER_PASS);
    
    // Bind anonymously
    $res = false;
    $dn = $uattr . '=' . $name;
    //srf
    global $ldap;
    //srf - the base dn is already passed as an argument to this function $anon_res = @ldap_search($this->connection, variable_get('ldap_base_dn', ''), $dn);
    $anon_res = @ldap_search($this->connection, $base_dn, $dn);
    //srf
    if ($anon_res) {
      if (ldap_count_entries($this->connection, $anon_res) !=1) {
        watchdog('user',"Error: Zero or more than 1 user found with $dn");
        return false;
      }
      //srf

      $users = @ldap_get_entries($this->connection, $anon_res);
      
      $this->disconnect();
      $this->establishConnection();

      $user_dn = $users[0]["dn"];
      $res = @ldap_bind($this->connection, $user_dn, $pass);
    }
    else {
      $this->disconnect();
    }
    ob_end_clean();
   
    return $res;
  }

  // Code contributed by sfrancis@drupal.org
  function name_to_dn_AD($uattr = '', $name = '', $base_dn = '') {
    global $ldap;

    $dn = $uattr . '=' . $name;
    $res = @ldap_search($this->connection, $base_dn, $dn);
    if ($res) {
      if (ldap_count_entries($this->connection, $res) !=1) {
        watchdog('user',"Error: Zero or more than 1 user found with $base_dn");
        return false;
      }
      $users = @ldap_get_entries($this->connection, $res);
      $user_dn = $users[0]["dn"];
    }

    return $user_dn;
  }
  
  function establishConnection() {
    if (!$con = ldap_connect($this->server, $this->port)) {
      watchdog('user', 'LDAP Connect failure to ' . $this->server . ':' . $this->port);
      return NULL;
    }
    $this->connection = $con;
    ldap_set_option($con, LDAP_OPT_PROTOCOL_VERSION, 3);
    // TLS encryption contributed by sfrancis@drupal.org
    if ($this->useTLS) {
      $vers = $this->getOption('version');
      if ($vers == -1) {
        watchdog('user', 'Could not get LDAP protocol version.');
      }
      
      if ($vers != 3) {
        watchdog('user', 'Could not start TLS, only supported by LDAP v3.');
      }
      else if (!ldap_start_tls($con)) {
        watchdog('user', t("Failed to start TLS on LDAP server. (Error %errno: %error).", array('%errno' => ldap_errno($con), '%error' => ldap_error($con))));
      }
    }
  }
  
  function connectAndBind($dn = '', $pass = '') {
    $this->establishConnection();

    $con = $this->connection;
    //die('con: ' . $con . ', dn: ' . $dn . ', pass: ' . $pass . ', server: ' . $this->server . ', port: ' . $this->port);
    // We don't want anonymous connections here
    if (!$dn || !$pass || !$this->bind($dn, $pass)) {
      watchdog('user', t('LDAP Bind failure for user %user. Error %errno: %error', array('%user' => $dn,'%errno' => ldap_errno($con), '%error' => ldap_error($con))));
      return NULL;
    }

    return $con;
  }
  
  function bind($dn, $pass) {
    ob_start();
    $ret = ldap_bind($this->connection, $dn, $pass);
    ob_end_clean();
    
    return $ret;
  }
  
  
  function disconnect() {
    if ($this->connection) {
      ldap_unbind($this->connection);
      $this->connection = NULL;
    }
  }
  
  // WARNING! WARNING! WARNING!
  // This function returns its entries with lowercase attribute names.
  // Don't blame me, blame PHP's own ldap_get_entries()
  function retrieveAttributes($dn) {
    $result = ldap_read($this->connection, $dn, 'objectClass=*');
    $entries = ldap_get_entries($this->connection, $result);
    
    return $entries[0];
  }
  
  function retrieveAttribute($dn, $attrname) {
    $entries = $this->retrieveAttributes($dn);
    
    return $entries[strtolower($attrname)][0];
  }
  
  function retrieveMultiAttribute($dn, $attrname) {
    $entries = $this->retrieveAttributes($dn);
    
    $result = array();
    $retrieved = $entries[strtolower($attrname)];
    $retrieved = $retrieved ? $retrieved : array();
    foreach ($retrieved as $key => $value) {
      if ($key !== 'count') {
        $result[] = $value;
      }
    }
    return $result;
  }
  
  function writeAttributes($dn, $attributes) {
    ldap_modify($this->connection, $dn, $attributes);
  }
}

?>