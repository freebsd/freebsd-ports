<?php
//
// +----------------------------------------------------------------------+
// | PHP Version 4                                                        |
// +----------------------------------------------------------------------+
// | Copyright (c) 1997-2002 The PHP Group                                |
// +----------------------------------------------------------------------+
// | This source file is subject to version 2.02 of the PHP license,      |
// | that is bundled with this package in the file LICENSE, and is        |
// | available at through the world-wide-web at                           |
// | http://www.php.net/license/2_02.txt.                                 |
// | If you did not receive a copy of the PHP license and are unable to   |
// | obtain it through the world-wide-web, please send a note to          |
// | license@php.net so we can mail you a copy immediately.               |
// +----------------------------------------------------------------------+
// | Authors: Manon Goo <manon@passionet.de>                              |
// |          Chuck Hagenbuch <chuck@horde.org>                           |
// +----------------------------------------------------------------------+

/**
* Class to emulate Perl's Crypt::HCE_MD5 module
* 
* The MIME Functions are tested and work symmetrically with the
* Crypt::HCE_MD5 package (0.45) (without the KEYBUG Flag ..).
* 
* Shamelessly stolen from Eric Estabrooks, eric@urbanrage.com
* Crypt::HCE_MD5 package:
* 
* This package implements a chaining block cipher using a one way
* hash. This method of encryption is the same that is used by radius
* (RFC2138) and is also described in Applied Cryptography by Bruce
* Schneider (p. 353 / "Karn").
* 
* Two interfaces are provided in the package. The first is straight
* block encryption/decryption the second does base64 mime
* encoding/decoding of the encrypted/decrypted blocks.
* 
* The idea is the the two sides have a shared secret that supplies one
* of the keys and a randomly generated block of bytes provides the
* second key. The random key is passed in cleartext between the two
* sides.
* 
* Usage:
* require_once 'Crypt/HCEMD5.php';
* $key = 'my secret key';
* srand((double)microtime()*32767);
* $rand = rand(1, 32767);
* $rand = pack('i*', $rand);
* $message = 'text to encrypt';
* $hcemd5 = new Crypt_HCEMD5($key, $rand);
* 
* // These Functions work with mime decoded Data
* $ciphertext = $hcemd5->encodeMime($message);
* $cleartext = $hcemd5->decodeMime($ciphertext);
* 
* // These Functions work with binary Data
* $ciphertext = $hcemd5->encrypt($message);
* $cleartext = $hcemd5->decrypt($ciphertext);
* 
* // These Functions work with mime decoded Data the selfrand
* // functions put the random value infront of the encrypted data to
* // be restored later
* $ciphertext = $hcemd5->encodeMimeSelfRand($message);
* $new_hcemd5 = new Crypt_HCEMD5($key, '');
* $cleartext = $new_hcemd5->DecodeMimeSelfRand($ciphertext);
*
* @version $Id: HCEMD5.php,v 1.8 2002/01/19 17:56:33 mj Exp $
* @access public
* @package Crypt
*/
class Crypt_HCEMD5 {
    
	/**
     * The first key to use. This should be a shared secret.
     * @var string
     */
	var $key;
    
	/**
     * The second key to use. This should be a randomly generated
     * block of bytes.
     * @var long
     */
	var $rand;
    
    
    /**
     * Creates a Crypt_HCEMD5 object.
     *
     * @param string The shared secret key
     * @param long   (optional) The randomly generated key
     *
     * @access public
     */
	function Crypt_HCEMD5($key, $rand = null) {
        $this->key = $key;
        
        if (!isset($rand)) {
            srand((double)microtime() * 32767);
            $rand = rand(1, 32767);
            $rand = pack('i*', $rand);
        }
        $this->rand = $rand;
	}
    
    
    /**
     * Encrypt a block of data.
     *
     * @param string The data to encrypt.
     * @return string The encrypted binary data.
     * @access public
     */
    function encrypt($data)
    {
	    $data = unpack('C*', $data);
        $ans = array();
        $ans1 = array(); 
        $eblock = 1;
        $e_block = $this->newKey($this->rand);
        $data_size = count($data);
        for ($i = 0; $i < $data_size; $i++) {
            $mod = $i % 16;
            if (($mod == 0) && ($i > 15)) {
       			$tmparr = array($ans[$i - 15],  $ans[$i - 14], $ans[$i - 13], $ans[$i - 12], $ans[$i - 11], $ans[$i - 10], $ans[$i - 9], $ans[$i - 8], $ans[$i - 7], $ans[$i - 6], $ans[$i - 5], $ans[$i - 4], $ans[$i - 3], $ans[$i - 2], $ans[$i - 1], $ans[$i] );
                $tmparr = $this->array2pack($tmparr);
                $tmparr = implode('', $tmparr);
                $e_block = $this->newKey($tmparr);
            }
            
            $mod++;
            $i++;
            $ans[$i] = $e_block[$mod] ^ $data[$i];
            $ans1[$i] = pack('C*', $ans[$i]);
            $i--;
            $mod--;
        }
	    return implode('', $ans1);
    }
    
    /**
     * Decrypt a block of data.
     *
     * @param string The data to decrypt.
     * @return string The decrypted binary data.
     * @access public
     */
    function decrypt($data)
    {
	    $data = unpack('C*', $data);
        $ans = array();
        $ans1 = array(); 
        $eblock = 1;
        $e_block = $this->newKey($this->rand);
        $data_size = count($data);
        for ($i = 0; $i < $data_size; $i++) {
            $mod = $i % 16;
            if (($mod == 0) && ($i > 15)) {
       			$tmparr = array($data[$i - 15], $data[$i - 14], $data[$i - 13], $data[$i - 12], $data[$i - 11], $data[$i - 10], $data[$i - 9], $data[$i - 8], $data[$i - 7], $data[$i - 6], $data[$i - 5], $data[$i - 4], $data[$i - 3], $data[$i - 2], $data[$i - 1], $data[$i]);
                $tmparr = $this->array2pack($tmparr);
                $tmparr = implode('', $tmparr);
                $e_block = $this->newKey($tmparr);
            }
            
            $mod++;
            $i++;
            $ans[$i] = $e_block[$mod] ^ $data[$i];
            $ans1[$i] = pack('C*', $ans[$i]);
            $i--;
        }
	    return implode('', $ans1);
    }
    
    /**
     * Encrypt a block of data after MIME-encoding it.
     *
     * @param string The data to encrypt.
     * @return string The encrypted mime-encoded data.
     * @access public
     */
    function encodeMime($data)
    {
        return base64_encode($this->encrypt($data));
    }
    
    /**
     * Decrypt a block of data and then MIME-decode it.
     *
     * @param string The data to decrypt.
     * @return string The decrypted mime-decoded data.
     * @access public
     */
    function decodeMime($data)
    {
        return $this->decrypt(base64_decode($data));
    }
    
    /**
     * Encrypt a block of data after MIME-encoding it, and include the
     * random hash in the final output in plaintext so it can be
     * retrieved and decrypted with only the secret key by
     * decodeMimeSelfRand().
     *
     * @param string The data to encrypt.
     * @param string The encrypted mime-encoded data, in the format: randkey#encrypted_data.
     * @access public
     */
    function encodeMimeSelfRand($data) {
		return base64_encode($this->rand) . '#' . $this->encodeMime($data);
    }
    
    /**
     * Decrypt a block of data and then MIME-decode it, using the
     * random key stored in beginning of the ciphertext generated by
     * encodeMimeSelfRand().
     *
     * @param string The data to decrypt, in the format: randkey#encrypted_data.
     * @return string The decrypted, mime-decoded data.
     * @access public
     */
    function decodeMimeSelfRand($data)
    {
        if (strpos($data, '#') === false) {
            return false;
        }
        
        list($rand, $data_crypt) = explode('#', $data);
        if (isset($data_crypt)) {
            $rand = base64_decode($rand);
            $this->rand = $rand;
            return $this->decodeMime($data_crypt);
        } else {
            return false;
        }
    }
    
    
    /**
     ** Support Functions
     **/
    
    /**
     * Implment md5 hashing in php, though use the mhash() function if it is available.
     *
     * @param string The string to hash.
     * @return string The md5 mhash of the string.
     * @access private
     */
    function binmd5($string)
    {
        if (extension_loaded('mhash')) {
            return mhash(MHASH_MD5, $string);
        }

        return pack('H*', md5($string));
    }
    
    /**
     * Turn an array into a binary packed string.
     *
     * @param array The array to pack.
     * @return string The binary packed representation of the array.
     * @access private
     */
    function array2pack($array)
    {
        $pack = array();
        foreach ($array as $val) {
            $pack[] = pack('C*', $val);
        }
        return $pack;
    }
	
	/**
     * Generate a new key for a new encryption block.
     *
     * @param string The basis for the key.
     * @param string The new key.
     * @access private
     */
	function newKey($round)
    {
        $digest = $this->binmd5($this->key . $round);
        return unpack('C*', $digest);
    }
    
}
?>
