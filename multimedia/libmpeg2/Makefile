# New ports collection makefile for:	libmpeg2
# Date created:		Tue Oct 16 17:14:20 BRST 2001
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmpeg2
PORTVERSION=	0.2.0
CATEGORIES=	graphics
MASTER_SITES=	http://libmpeg2.sourceforge.net/files/
DISTNAME=	mpeg2dec-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

USE_XLIB=	yes
USE_AUTOCONF=   yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS= --enable-shared

.ifdef(WITH_MGA)
CONFIGURE_ARGS+=	--enable-mga
.endif

.ifdef(WITH_SDL)
LIB_DEPENDS+=	SDL-1.1.3:${PORTSDIR}/devel/sdl12

EXTRA_PATCHES+=	${FILESDIR}/extra-patch-libvo::configure.incl \
		${FILESDIR}/extra-patch-libvo::video_out_sdl.c
SDL_CONFIG?=    ${LOCALBASE}/bin/sdl11-config

CONFIGURE_ENV+=  SDL_CONFIG="${SDL_CONFIG}"
CONFIGURE_ARGS+=	--enable-sdl
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif

pre-everything::
	@${ECHO_MSG} "====>"
.ifndef(WITH_SDL)
	@${ECHO_MSG} "====> You can enable SDL support by defining WITH_SDL"
.endif
.ifndef(WITH_MGA)
	@${ECHO_MSG} "====> You can enable MGA support by defining WITH_MGA"
.endif
	@${ECHO_MSG} "====>"

post-configure:
	@${LN} -sf ${LOCALBASE}/bin/libtool ${WRKSRC}
# Libtool fix code kindly provided by Mr. Maxim Sobolev <sobomax@FreeBSD.org>
	@${PERL} -pi.orig \
		-e 's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
		${WRKSRC}/libtool

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/libvo.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
