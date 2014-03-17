# $FreeBSD$

PORTNAME=	libva
PORTVERSION=	1.2.1
CATEGORIES=	multimedia
MASTER_SITES=	http://cgit.freedesktop.org/${PORTNAME}/snapshot/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	VAAPI wrapper and dummy driver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	libdrm.so:${PORTSDIR}/graphics/libdrm

USES=		pkgconfig tar:bzip2
USE_XORG=	glproto pciaccess xext xfixes 
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

OPTIONS_DEFINE=	DEBUG

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CFLAGS+=	-D_DEBUG
.else
CFLAGS+=	-DNDEBUG
.endif

.include <bsd.port.pre.mk>

# add strnlen(3) from head/lib/libc/string/strnlen.c
.if ${OSVERSION} < 800067
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-va-va_trace.c
.endif

.if ${ARCH} == "sparc64"
BROKEN=		glXCreateContext fails during configure
.endif

.if defined(STRIP) && ${STRIP} != ""
INSTALL_TARGET=	install-strip
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -e 's|\($$libdir\)/dri|\1/va|' \
		-e 's|$${libdir}/\(pkgconfig\)|$${prefix}/libdata/\1|' \
		-e 's/\(LIBVA_LT_CURRENT\)=libva_lt_current/\1=1/' \
		-e 's/\(LIBVA_LT_REV\)=libva_lt_revision/\1=3301/' \
		-e 's/\(LIBVA_LT_AGE\)=libva_lt_age/\1=0/' \
		${WRKSRC}/configure.ac
	${REINPLACE_CMD} -e 's/va\(info\)/\1/g' -e 's/info\.c/vainfo\.c/' \
		${WRKSRC}/test/vainfo/Makefile.am
	${REINPLACE_CMD} '/^export VA_HEADER_/d' \
		${WRKSRC}/doc/Makefile.am
	${REINPLACE_CMD} 's/-ldl//' ${WRKSRC}/va/Makefile.am

# XXX: work around an issue with automake-1.13 erroring out on a
#      non-existent m4 directory before libtoolize creates it
pre-configure::
	@${MKDIR} ${WRKSRC}/m4

post-configure:	.SILENT
	${REINPLACE_CMD} 's/-lpthread/${PTHREAD_LIBS}/' \
		${WRKSRC}/test/putsurface/Makefile

.include <bsd.port.post.mk>
