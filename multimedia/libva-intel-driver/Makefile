# Created by: Manuel Creach <manuel.creach@me.com>
# $FreeBSD$

PORTNAME=	libva-intel-driver
PORTVERSION=	1.7.2
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.freedesktop.org/software/vaapi/releases/${PORTNAME}/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	VAAPI intel driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libva.so:multimedia/libva
BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat

GNU_CONFIGURE=	yes
USES=		alias autoreconf compiler:c11 gmake libtool localbase \
		pkgconfig tar:bzip2
USE_GL=		gl
USE_LDCONFIG=	yes

PLIST_FILES=	lib/va/i965_drv_video.so

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Driver for hardware present only on intel i386 and amd64 CPUs

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's/-ldl//' \
		${WRKSRC}/src/Makefile.am
	${REINPLACE_CMD} -e 's|driverdir|& --define-variable prefix=${PREFIX}|' \
		${WRKSRC}/configure.ac

.include <bsd.port.mk>
