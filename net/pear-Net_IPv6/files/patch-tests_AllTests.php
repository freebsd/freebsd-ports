--- tests/AllTests.php.orig	2022-08-11 19:31:42 UTC
+++ tests/AllTests.php
@@ -19,6 +19,7 @@ require_once "Net/IPv6.php";
 // $Id: AllTests.php 340792 2016-10-29 14:56:52Z alexmerz $
 
 require_once "Net/IPv6.php";
+use PHPUnit\Framework\TestCase;
 
 /**
 * This testcases tests for several bugs and general topics
@@ -28,7 +29,7 @@ require_once "Net/IPv6.php";
 * @version $Id: AllTests.php 340792 2016-10-29 14:56:52Z alexmerz $
 * @access  public
 */
-class NetIPv6Test extends PHPUnit_Framework_TestCase {
+class AllTests extends TestCase {
 
     protected $ip;
 
@@ -39,7 +40,7 @@ class NetIPv6Test extends PHPUnit_Framework_TestCase {
         return $method;
     }
 
-    public function setUp() {
+    public function setUp(): void {
         $this->ip = new Net_IPv6();
     }
 
@@ -742,6 +743,109 @@ class NetIPv6Test extends PHPUnit_Framework_TestCase {
         $netmask = '::ffff/96';
         $testip = '0:0:0:0:0:ffff:c000:22f';
         $this->assertTrue(Net_IPv6::isInNetmask($testip, $netmask));
+    }
+
+    /**
+     * tests if checkIPv6 can handle addresses with zone
+     * @author Reid Linnemann <rlinnemann@netgate.com>
+     */
+    public function testCheckIPv6WithZone() {
+        $testip = 'fe80::de:ad:be:ef%zone.name';
+        $is = $this->ip->checkIPv6($testip);
+
+        $this->assertTrue($is);
+    }
+
+    /**
+     * tests if splitV64 can handle addresses with zone
+     * @author Reid Linnemann <rlinnemann@netgate.com>
+     */
+    public function testSplitV64WithZone() {
+        $testip = 'fe80::de:ad:be:ef%zone.name';
+        $zonelessip = 'fe80::de:ad:be:ef';
+        $items = $this->ip->SplitV64($testip, false);
+
+        $this->assertEquals(2, count($items));
+        $this->assertEmpty($items[1]);
+        $this->assertEquals($zonelessip, $items[0]);
+    }
+
+    /**
+     * tests zoned address compression
+     * @author Reid Linnemann
+     */
+    public function testCompressWithZone() {
+        $uncompressedip = 'fe80:0:0:0:de:ad:be:ef%zone.name';
+        $compressedip = 'fe80::de:ad:be:ef%zone.name';
+
+        $testip = $this->ip->compress($uncompressedip, false);
+
+        $this->assertEquals($compressedip, $testip);
+    }
+
+    /**
+     * tests zoned address compression with IPv4 part
+     * @author Reid Linnemann
+     */
+    public function testCompressWithIPv4AndZone() {
+        $uncompressedip = 'fe80:0:0:0:dead:beef:172.10.1.1%zone.name';
+        $compressedip = 'fe80::dead:beef:172.10.1.1%zone.name';
+
+        $testip = $this->ip->compress($uncompressedip, false);
+
+        $this->assertEquals($compressedip, $testip);
+    }
+
+    /**
+     * tests zoned address with prefix compression with IPv4 part
+     * @author Reid Linnemann
+     */
+    public function testCompressWithIPv4AndZoneAndPrefix() {
+        $uncompressedip = 'fe80:0:0:0:dead:beef:172.10.1.1%zone.name/64';
+        $compressedip = 'fe80::dead:beef:172.10.1.1%zone.name/64';
+
+        $testip = $this->ip->compress($uncompressedip, false);
+
+        $this->assertEquals($compressedip, $testip);
+    }
+
+    /**
+     * tests zoned address uncompression
+     * @author Reid Linnemann
+     */
+    public function testUncompressWithZone() {
+        $uncompressedip = 'fe80:0:0:0:de:ad:be:ef%zone.name';
+        $compressedip = 'fe80::de:ad:be:ef%zone.name';
+
+        $testip = $this->ip->uncompress($compressedip, false);
+
+        $this->assertEquals($uncompressedip, $testip);
+    }
+
+    /**
+     * tests zoned address uncompression with IPv4 part
+     * @author Reid Linnemann
+     */
+    public function testUncompressWithIPv4AndZone() {
+        $uncompressedip = 'fe80:0:0:0:dead:beef:172.10.1.1%zone.name';
+        $compressedip = 'fe80::dead:beef:172.10.1.1%zone.name';
+
+        $testip = $this->ip->uncompress($compressedip, false);
+
+        $this->assertEquals($uncompressedip, $testip);
+    }
+
+    /**
+     * tests zoned address with prefix uncompression with IPv4 part
+     * @author Reid Linnemann
+     */
+    public function testUncompressWithIPv4AndZoneAndPrefix() {
+        $uncompressedip = 'fe80:0:0:0:dead:beef:172.10.1.1%zone.name/64';
+        $compressedip = 'fe80::dead:beef:172.10.1.1%zone.name/64';
+
+        $testip = $this->ip->uncompress($compressedip, false);
+
+        $this->assertEquals($uncompressedip, $testip);
     }
 
-}
\ No newline at end of file
+}
