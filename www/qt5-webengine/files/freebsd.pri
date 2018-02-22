include(desktop_linux.pri)

gn_args +=   disable_nacl=true           \
             enable_basic_printing=true \
             enable_print_preview=true \
             enable_pdf=true \
             enable_webrtc=true   \
             enable_hidpi=true      \
             use_dbus=true           \
             enable_plugins=false	\
             enable_widevine=false

# Once the port works better, we can think about readding the diverse `use_system_<foo>`
# for bundled libraries.
# For now, only add very few system libraries.
gn_args += use_system_yasm=true   \
           use_system_libusb=true \
           use_system_libcxx=true
