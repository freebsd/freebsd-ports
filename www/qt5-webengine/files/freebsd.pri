include(desktop_linux.pri)

GYP_CONFIG +=   disable_nacl=1          \
                enable_basic_printing=0 \
                enable_printing=0       \
                enable_webrtc=0         \
                enable_hidpi=1          \
                use_dbus=1              \
                use_pulseaudio=0

# Once the port works better, we can think about readding the diverse `use_system_<foo>`
# for bundled libraries.
# For now, only add very few system libraries.
GYP_CONFIG += use_system_yasm=1 \
              use_system_libusb=1 \
              use_system_libcxx=1
