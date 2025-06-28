PORTNAME=	lms
DISTVERSIONPREFIX=	v
DISTVERSION=	3.67.0
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight Music Server to access music using a web interface
WWW=		https://github.com/epoupon/lms

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	googletest>0:devel/googletest
LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libboost_system.so:devel/boost-libs \
		libconfig++.so:devel/libconfig \
		libtag.so:audio/taglib \
		libwthttp.so:www/wt \
		libxxhash.so:devel/xxhash
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		cmake compiler:c++20-lang cpe libarchive pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	epoupon

CMAKE_OFF=	ENABLE_TESTS

USER=		nobody
GROUP=		nobody
SUB_LIST=	USER=${USER}
USE_RC_SUBR=	${PORTNAME}

PLIST_SUB=	USER="${USER}" GROUP="${GROUP}"

OPTIONS_RADIO=			IMAGE_LIB
OPTIONS_RADIO_IMAGE_LIB=	STB MAGICK
OPTIONS_DEFAULT=		STB # STB is prefered by the upstream

STB_DESC=			Use STB as image library (uses less memory)
STB_BUILD_DEPENDS=		${LOCALBASE}/include/stb/stb_image.h:devel/stb
STB_CMAKE_CMAKE_ON=		-DLMS_IMAGE_BACKEND:STRING=stb

MAGICK_DESC=			Use GraphicsMagick++ as image library
MAGICK_LIB_DEPENDS=		libGraphicsMagick.so:graphics/GraphicsMagick
MAGICK_CMAKE_ON=		-DLMS_IMAGE_BACKEND:STRING=graphicsmagick

.include <bsd.port.options.mk>
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1400000
USES+=		llvm:17 # fix the build failure on 13: error: object of type 'const lms::core::LiteralString' cannot be compared because its 'operator<=>' is implicitly deleted
.else
USES+=		compiler:c++20-lang
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|"/etc"|"${PREFIX}/etc"|' \
		${WRKSRC}/src/libs/core/include/core/SystemPaths.hpp
	@${REINPLACE_CMD} -e 's|"/usr/|"${PREFIX}/|; s|"/var/lms/"|"/var/db/lms/"|' \
		${WRKSRC}/conf/lms.conf

post-install:
	# link sample
	${RLN} ${STAGEDIR}${DATADIR}/lms.conf ${STAGEDIR}${PREFIX}/etc/lms.conf.sample
	# create the DB directory
	${MKDIR} ${STAGEDIR}/var/db/lms
	# install the PAM config file # PAM breaks, see https://github.com/epoupon/lms/issues/210
	${RLN} ${STAGEDIR}${DATADIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/etc/pam.d/${PORTNAME}

.include <bsd.port.mk>
