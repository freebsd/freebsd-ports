--- src/usb_bus.cpp.orig	2021-08-09 11:19:20 UTC
+++ src/usb_bus.cpp
@@ -28,6 +28,12 @@
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
+#ifdef __FreeBSD__
+#include <stdint.h>
+#include <sys/endian.h>
+#include <dev/usb/usb_pf.h>
+#endif
+
 #include <usbtop/usb_bus.h>
 #include <usbtop/tools.h>
 
@@ -41,8 +47,26 @@ usbtop::UsbBus::~UsbBus()
 	}
 }
 
+#ifdef __FreeBSD__
 void usbtop::UsbBus::push(const pcap_pkthdr* h, const u_char* bytes)
 {
+	const size_t psize = h->len;
+	const double time = (double)h->ts.tv_sec + ((double)h->ts.tv_usec) / 1000000.0;
+	const struct usbpf_pkthdr *up = (const struct usbpf_pkthdr *)bytes;
+	size_t payload;
+	UsbStats::direction_type direction;
+
+	if (psize < sizeof(*up))
+		return;
+
+	payload = le32toh(up->up_totlen) - sizeof(*up) - le32toh(up->up_frames) * USBPF_FRAME_HDR_LEN;
+	direction = (up->up_type == USBPF_XFERTAP_DONE) ? UsbStats::from_device : UsbStats::to_device;
+	_stats.push(time, payload, direction);
+	get_device(up->up_address).push(time, payload, direction);
+}	
+#else
+void usbtop::UsbBus::push(const pcap_pkthdr* h, const u_char* bytes)
+{
 	// Get the packet size and timestamp
 	const size_t psize = h->len;
 	const double time = (double)h->ts.tv_sec + ((double)h->ts.tv_usec)/(1000000.0);
@@ -72,3 +96,4 @@ void usbtop::UsbBus::push(const pcap_pkthdr* h, const 
 	_stats.push(time, psize, direction);
 	get_device(device_id).push(time, psize, direction);
 }
+#endif
