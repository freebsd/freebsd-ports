# ex:ts=8
# Ports collection makefile for:	GOPchop
# Date created:				Apr 24, 2002
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	gopchop
PORTVERSION=	0.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://outflux.net/unix/software/GOPchop/download/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	GOPchop-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libvo.a:${PORTSDIR}/graphics/libmpeg2
LIB_DEPENDS=	mpeg2:${PORTSDIR}/graphics/libmpeg2 \
		SDL-1.1:${PORTSDIR}/devel/sdl12 \
		gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS} -D__GNU_LIBRARY__" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lSDL-1.1 -lgnugetopt"

post-patch:
	@${REINPLACE_CMD} -e "s|-lSDL|-lSDL-1.1|g" \
		-e "s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|-lglib||g" ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
