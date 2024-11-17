FF_SUFFIX=	3

BUILD_DEPENDS:=	${BUILD_DEPENDS:S/ffmpeg/&${FF_SUFFIX}/g}
LIB_DEPENDS:=	${LIB_DEPENDS:S/ffmpeg$/&${FF_SUFFIX}/}

USES+=		localbase # -isystem
CONFIGURE_ENV+=	PKG_CONFIG_PATH="${LOCALBASE}/ffmpeg${FF_SUFFIX}/libdata/pkgconfig"
MAKE_ENV+=	PKG_CONFIG_PATH="${LOCALBASE}/ffmpeg${FF_SUFFIX}/libdata/pkgconfig"
