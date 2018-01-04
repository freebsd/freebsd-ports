# $FreeBSD$

PORTNAME=	libva-utils
PORTVERSION=	2.0.0
CATEGORIES=	multimedia

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Collection of tests and utilities for VAAPI

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libva.so:multimedia/libva

USES=		autoreconf gmake libtool pkgconfig tar:bzip2
#USE_XORG=	glproto pciaccess xext xfixes
#USE_GL=	gl
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	01org

#LDFLAGS+=	-lpthread
# prevent types conflict: videodev2.h vs. drm.h
#CFLAGS+=	-DHAVE_LINUX_INTEGER_TYPES

OPTIONS_DEFINE=	DEBUG

DEBUG_CFLAGS=		-D_DEBUG
DEBUG_CFLAGS_OFF=	-DNDEBUG

#post-patch:	.SILENT
#	${REINPLACE_CMD} -e 's|\($$libdir\)/dri|\1/va|' \
#		-e 's|$${libdir}/\(pkgconfig\)|${PREFIX}/libdata/\1|' \
#		${WRKSRC}/configure.ac
#	${REINPLACE_CMD} -e 's/va\(info\)/\1/g' -e 's/info\.c/vainfo\.c/' \
#		${WRKSRC}/test/vainfo/Makefile.am
#	${REINPLACE_CMD} '/^export VA_HEADER_/d' \
#		${WRKSRC}/doc/Makefile.am
#	${REINPLACE_CMD} 's/-ldl//' ${WRKSRC}/va/Makefile.am

.include <bsd.port.mk>
