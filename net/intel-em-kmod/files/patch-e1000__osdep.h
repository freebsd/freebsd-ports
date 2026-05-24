--- e1000_osdep.h.orig	2020-04-08 15:13:17 UTC
+++ e1000_osdep.h
@@ -134,7 +134,7 @@ struct e1000_osdep
 	bus_space_handle_t io_bus_space_handle;
 	bus_space_tag_t    flash_bus_space_tag;
 	bus_space_handle_t flash_bus_space_handle;
-	struct device     *dev;
+	device_t	   dev;
 };
 
 #define E1000_REGISTER(hw, reg) (((hw)->mac.type >= e1000_82543) \
