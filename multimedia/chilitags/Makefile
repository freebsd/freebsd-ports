# $FreeBSD$

PORTNAME=	chilitags
DISTVERSION=	2.0.0-169
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g0d9854f
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Robust fiducial markers for augmented reality and robotics

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/gpl.txt

LIB_DEPENDS=	libopencv_imgproc.so:graphics/opencv-core \
		libopencv_video.so:graphics/opencv

USES=		cmake:outsource
USE_GITHUB=	yes
GH_ACCOUNT=	chili-epfl
USE_LDCONFIG=	yes

PLIST_FILES=	bin/chilitags-creator \
		include/chilitags/chilitags.hpp \
		include/chilitags/chilitags_export.hpp \
		lib/libchilitags.so \
		libdata/pkgconfig/chilitags.pc

post-install:
		@${RM} ${STAGEDIR}${PREFIX}/lib/libchilitags_static.a

.include <bsd.port.mk>
