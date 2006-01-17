<?php
// $Id: conf.php,v 1.1.4.4 2005/10/29 19:09:30 pablobm Exp $

/*
 * Interesting constants that admins would want to mess with
 */

// Admin must define a user able to write users' attributes (to generate new passwords when they are lost)
define(LDAP_WRITER_USER_DN, 'cn=writer,dc=example,dc=com');
define(LDAP_WRITER_USER_PASS, 'secret');

// Admin must define a user able to read users' attributes (to read e-mail addresses when passwords are lost)
define(LDAP_READER_USER_DN, 'cn=reader,dc=example,dc=com');
define(LDAP_READER_USER_PASS, 'secret');

$GLOBALS['ldap_drupal_mappings'] = array(
	// ldap_attribute => drupal field
	// 'cn' => 'name',
	'mailAddress' => 'mail',
	'userPassword' => 'pass',
	//'signature' => 'signature',
	//'timeZome' => 'timezone'
);

/*
 * Edit this list so that all attributes that you might wish to show
 * are included. You may then enable/disable attributes in the Admin page.
 *
 * The left hand element indicates the LDAP attribute name.
 *
 * The 1st right hand elements in the array determine how the attribute and
 * its value are displayed. The first element may be 'text', 'image', or 'url'.
 */

$GLOBALS['ldap_attributes'] = array(
  'givenName'     => array('text', 'textfield', t('First Name'), 64, 64),
  'userPassword'      => array('pass', 'password', t('Password'), 64, 64),
  'initials'      => array('text', 'textfield', t('Initial'), 64, 4, t('Your middle initial.')),      
  'sn'            => array('text', 'textfield', t('Last Name'), 64, 64), //aka Surname
  'cn'            => array('text', 'textfield', t('Common Name'), 64, 64),      
  'displayName'   => array('text', 'textfield', t('Display Name'), 64, 64),      
  'mail'          => array('mailto', 'textfield', t('Email'), 64, 64, ''),
  'description'   => array('text', 'textfield', t('Description'), 64, 64, ''),            
  'postOfficeBox' => array('text', 'textfield', t('P.O. Box'), 64, 64),      
  'streetaddress' => array('text', 'textfield', t('Address'), 64, 64),
  'l'             => array('text', 'textfield', t('City'), 64, 64, t('Your city or other location')),
  'st'            => array('text', 'textfield', t('State'), 4, 2, t('Your state or province')),
  'postalCode'    => array('text', 'textfield', t('Postal Code'), 7, 5, t('Your Zip or Postal code')),
  'co'            => array('text', 'textfield', t('Country'), 64, 64, t('Country or region')),  
  'company'       => array('text', 'textfield', t('Company'), 12, 12, 'Company or organization'),
  'title'         => array('text', 'textfield', t('Title'), 12, 12),
  'department'    => array('text', 'textfield', t('Department'), 64, 64),
  'physicalDeliveryOfficeName' => array('text', 'textfield', t('Office'), 64, 64, ''),      
  'homephone'     => array('text', 'textfield', t('Home Phone'), 64, 64, ''),
  'mobile'        => array('text', 'textfield', t('Mobile Phone'), 64, 64, ''),
  'otherTelephone' => array('text', 'textfield', t('Other Phone'), 64, 64, ''),
  'wWWHomePage'   => array('image', 'textfield', t('Web Page'), 64, 64, ''),
  'url'           => array('link', 'textfield', t('Other web pages'), 64, 64, ''),
  'roomNumber'    => array('text', 'textfield', t('Office Location'), 64, 64, ''),
  'telephoneNumber' => array('text', 'textfield', t('Office Phone'), 64, 64, ''),
        
  // examples of displaying attributes in Select menus or TextArea boxes. Helpful for composing search queries      
  'gender'        => array('text', 'select', t('Gender'), array(0 => '-', 'm' => t('male'), 'f' => t('female')), 'Pick a gender', 0, 0),      
  'publickey'     => array('text', 'textarea', t('Public key'), 64, 4, ''));

?>
