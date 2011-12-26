# New ports collection makefile for:	libva
# Date created:				5 Jan 2011
# Whom:					Anonymous
#
# $FreeBSD$
#

PORTNAME=	libva
PORTVERSION=	1.0.14
CATEGORIES=	multimedia
MASTER_SITES=	http://cgit.freedesktop.org/${PORTNAME}/snapshot/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VAAPI wrapper and dummy driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	drm.2:${PORTSDIR}/graphics/libdrm

USE_BZIP2=	yes
USE_XORG=	pciaccess xext xfixes
USE_GL=		gl
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtoolize
ACLOCAL_ARGS=	-I.
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ARGS=	--program-prefix=va
USE_LDCONFIG=	yes

CPPFLAGS+=	-isystem${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
# prevent types conflict: videodev2.h vs. drm.h
CFLAGS+=	-DHAVE_LINUX_INTEGER_TYPES

.include <bsd.port.pre.mk>

# add strnlen(3) from head/lib/libc/string/strnlen.c
.if ${OSVERSION} < 800067
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-va-va_trace.c
.endif

.if ${ARCH} == "sparc64"
BROKEN=		glXCreateContext fails during configure
.endif

.if !defined(WITH_DEBUG)
CFLAGS+=	-DNDEBUG
.else
CFLAGS+=	-D_DEBUG
.endif

.if defined(STRIP) && ${STRIP} != ""
INSTALL_TARGET=	install-strip
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's|\($$libdir\)/dri|\1/va|' \
		-e 's|$${libdir}/\(pkgconfig\)|$${prefix}/libdata/\1|' \
		${WRKSRC}/configure.ac
	${REINPLACE_CMD} 's/va\(info\)/\1/' \
		${WRKSRC}/test/vainfo/Makefile.am
	${REINPLACE_CMD} 's/-ldl//' ${WRKSRC}/va/Makefile.am

post-configure:	.SILENT
	${REINPLACE_CMD} 's/-lpthread/${PTHREAD_LIBS}/' \
		${WRKSRC}/i965_drv_video/Makefile \
		${WRKSRC}/test/putsurface/Makefile

.include <bsd.port.post.mk>
