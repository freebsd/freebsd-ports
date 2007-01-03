# New ports collection makefile for:	gavl
# Date created:		2004-08-29
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	gavl
PORTVERSION=	0.2.5
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gmerlin

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A library for handling uncompressed video and audio data

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		samplerate.1:${PORTSDIR}/audio/libsamplerate

USE_GNOME=	pkgconfig gnometarget gnomehack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--without-cpuflags

PORTDOCS=	README

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 504000
EXTRA_PATCHES=	${PATCHDIR}/gavl-mix.c-patch \
		${PATCHDIR}/gavl-c-_cmix_c.c-patch
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===>  Enable Optimized CFLAGS by defining"
	@${ECHO_MSG} "===>   WITH_OPTIMIZED_CFLAGS"
	@${ECHO_MSG} "===>"
.endif

post-patch:
# No llrintf in freebsd (yet)
.if ${OSVERSION} < 504000
	@${REINPLACE_CMD} -e 's|llrintf|rintf|g' \
		${WRKSRC}/gavl/c/*.*
.endif
	@${REINPLACE_CMD} -e 's|CFLAGS="-Wall|CFLAGS="${CFLAGS} -Wall|g' \
		${WRKSRC}/configure
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e \
	's|-O3 -funroll-all-loops -fomit-frame-pointer -ffast-math||g' \
		${WRKSRC}/configure
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
