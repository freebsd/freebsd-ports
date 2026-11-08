# cmake/FindWebP.cmake
find_package(PkgConfig REQUIRED)

# 1. Look for core webp
pkg_check_modules(PC_WEBP QUIET libwebp)
find_path(WebP_INCLUDE_DIR NAMES webp/decode.h HINTS ${PC_WEBP_INCLUDEDIR})
find_library(WebP_LIBRARY NAMES webp HINTS ${PC_WEBP_LIBDIR})

# 2. Look for webpdemux
pkg_check_modules(PC_WEBP_DEMUX QUIET libwebpdemux)
find_path(WebP_DEMUX_INCLUDE_DIR NAMES webp/demux.h HINTS ${PC_WEBP_DEMUX_INCLUDEDIR})
find_library(WebP_DEMUX_LIBRARY NAMES webpdemux HINTS ${PC_WEBP_DEMUX_LIBDIR})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(WebP DEFAULT_MSG 
    WebP_LIBRARY WebP_INCLUDE_DIR 
    WebP_DEMUX_LIBRARY WebP_DEMUX_INCLUDE_DIR
)

# Define the WebP::webp target
if(WebP_FOUND AND NOT TARGET WebP::webp)
    add_library(WebP::webp UNKNOWN IMPORTED)
    set_target_properties(WebP::webp PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${WebP_INCLUDE_DIR}"
        IMPORTED_LOCATION "${WebP_LIBRARY}"
    )
endif()

# Define the WebP::webpdemux target expected by torchcodec
if(WebP_FOUND AND NOT TARGET WebP::webpdemux)
    add_library(WebP::webpdemux UNKNOWN IMPORTED)
    set_target_properties(WebP::webpdemux PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${WebP_DEMUX_INCLUDE_DIR}"
        IMPORTED_LOCATION "${WebP_DEMUX_LIBRARY}"
        INTERFACE_LINK_LIBRARIES WebP::webp
    )
endif()

