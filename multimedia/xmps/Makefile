# New ports collection makefile for:	xmps
# Date created:				15 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmps
PORTVERSION=	0.2.0
CATEGORIES=	multimedia gnome
MASTER_SITES=	http://xmps.sourceforge.net/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X MPEG Player System - a media player with a very nice GUI

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gdkpixbuf
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		SDL_CONFIG="${SDL_CONFIG}" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | xargs ${REINPLACE_CMD} -e \
		 's|-lpthread|${PTHREAD_LIBS}|g'

post-configure:
	@${REINPLACE_CMD} -e 's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
		${WRKSRC}/libtool

.include <bsd.port.post.mk>
