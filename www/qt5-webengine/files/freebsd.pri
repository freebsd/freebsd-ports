include(linux.pri)

gn_args +=   enable_basic_printing=true	\
             enable_print_preview=true	\
             use_dbus=true \
             use_udev=false

# Once the port works better, we can think about readding the diverse `use_system_<foo>`
# for bundled libraries.
# For now, only add very few system libraries.
gn_args += use_system_yasm=true
