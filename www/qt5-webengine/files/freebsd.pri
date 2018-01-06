include(desktop_linux.pri)

gn_args +=   disable_nacl=true           \
             enable_basic_printing=false \
             enable_webrtc=false         \
             enable_hidpi=true           \
             use_dbus=true               \
             use_pulseaudio=false

# Once the port works better, we can think about readding the diverse `use_system_<foo>`
# for bundled libraries.
# For now, only add very few system libraries.
gn_args += use_system_yasm=true   \
           use_system_libusb=true \
           use_system_libcxx=true
