# New ports collection makefile for:	kissd
# Date created:				25 Aug 2005
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	kissd
PORTVERSION=	0.1
CATEGORIES=	net multimedia
MASTER_SITES=	http://rink.nu/downloads/projects/

MAINTAINER=	ed@fxq.nl
COMMENT=	A daemon for providing multimedia files to KiSS DP-50x players

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/kissd

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^AM_CFLAGS/ s|-Werror|${PTHREAD_CFLAGS}|' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
