PORTNAME=	tudu
PORTVERSION=	0.10.3
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://code.meskio.net/tudu/

MAINTAINER=	mp39590@gmail.com
COMMENT=	Command line program for managing "todo" lists
WWW=		https://code.meskio.net/tudu/

LICENSE=	GPLv3

USES=		ncurses
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

post-patch:
	@${REINPLACE_CMD} -E 's|cd (.+) && (\$$\{MAKE\})|\2 -C \1|' \
		${WRKSRC}/Makefile.acr
	@${REINPLACE_CMD} -e '/tudurc/s,SYSCONFDIR),&/tudurc.sample,' \
		${WRKSRC}/data/Makefile.acr

.include <bsd.port.mk>
