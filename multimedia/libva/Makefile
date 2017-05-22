# $FreeBSD$

PORTNAME=	libva
PORTVERSION=	1.8.1
PORTREVISION=	2
CATEGORIES=	multimedia

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	VAAPI wrapper and dummy driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
RUN_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libdrm.so:graphics/libdrm

USES=		autoreconf gmake libtool localbase pkgconfig tar:bzip2
USE_XORG=	glproto pciaccess xext xfixes
USE_GL=		gl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=va
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	01org

LDFLAGS+=	-lpthread
# prevent types conflict: videodev2.h vs. drm.h
CFLAGS+=	-DHAVE_LINUX_INTEGER_TYPES

OPTIONS_DEFINE=	DEBUG

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CFLAGS+=	-D_DEBUG
.else
CFLAGS+=	-DNDEBUG
.endif

.include <bsd.port.pre.mk>

.if defined(STRIP) && ${STRIP} != ""
INSTALL_TARGET=	install-strip
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's|\($$libdir\)/dri|\1/va|' \
		-e 's|$${libdir}/\(pkgconfig\)|${PREFIX}/libdata/\1|' \
		${WRKSRC}/configure.ac
	${REINPLACE_CMD} '/^export VA_HEADER_/d' \
		${WRKSRC}/doc/Makefile.am
	${REINPLACE_CMD} 's/-ldl//' ${WRKSRC}/va/Makefile.am

.include <bsd.port.post.mk>
