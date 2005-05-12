# New ports collection makefile for:	gavl
# Date created:		2004-08-29
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	gavl
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gmerlin

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	A library for handling uncompressed video and audio data

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		samplerate.1:${PORTSDIR}/audio/libsamplerate

USE_LIBTOOL_VER=	15
USE_REINPLACE=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

USE_GNOME=	pkgconfig gnometarget gnomehack
INSTALLS_SHLIB=	yes

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
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e \
	's|-fomit-frame-pointer -funroll-all-loops -falign-functions=2 -falign-loops=2 -falign-jumps=2||; \
	 s|-O3||' ${WRKSRC}/configure
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
