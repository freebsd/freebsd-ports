Upstream PR:
https://github.com/Aquantia/aqtion-freebsd/pull/11

--- aq_hw.c.orig	2019-09-24 14:45:34 UTC
+++ aq_hw.c
@@ -160,7 +160,7 @@ static int aq_hw_init_ucp(struct aq_hw *hw)
             unsigned int rnd = 0;
             unsigned int ucp_0x370 = 0;
 
-            rnd = random();
+            rnd = arc4random();
 
             ucp_0x370 = 0x02020202 | (0xFEFEFEFE & rnd);
             AQ_WRITE_REG(hw, AQ_HW_UCP_0X370_REG, ucp_0x370);
@@ -307,7 +307,6 @@ int aq_hw_get_mac_permanent(struct aq_hw *hw,  u8 *mac
 
     /* Couldn't get MAC address from HW. Use auto-generated one. */
     if ((mac[0] & 1) || ((mac[0] | mac[1] | mac[2]) == 0)) {
-        u64 seed = get_cyclecount();
         u16 rnd;
         u32 h = 0;
         u32 l = 0;
@@ -315,7 +314,6 @@ int aq_hw_get_mac_permanent(struct aq_hw *hw,  u8 *mac
         printf("atlantic: HW MAC address %x:%x:%x:%x:%x:%x is multicast or empty MAC", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
         printf("atlantic: Use random MAC address");
 
-        srandom(seed);
         rnd = random();
 
         /* chip revision */
