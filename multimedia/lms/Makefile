PORTNAME=	lms
DISTVERSIONPREFIX=	v
DISTVERSION=	3.45.2
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
		libwthttp.so:www/wt
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		cmake compiler:c++17-lang cpe libarchive pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	epoupon

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
STB_CMAKE_BOOL=			FREEBSD_USE_STB

MAGICK_DESC=			Use GraphicsMagick++ as image library
MAGICK_LIB_DEPENDS=		libGraphicsMagick.so:graphics/GraphicsMagick
MAGICK_CMAKE_BOOL=		FREEBSD_USE_MAGICK

post-patch:
	@${REINPLACE_CMD} -e 's|"/etc/lms.conf"|"${PREFIX}/etc/lms.conf"|' \
		${WRKSRC}/src/lms/main.cpp \
		${WRKSRC}/src/tools/cover/LmsCover.cpp \
		${WRKSRC}/src/tools/recommendation/LmsRecommendation.cpp
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
