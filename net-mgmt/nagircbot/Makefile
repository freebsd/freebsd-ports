PORTNAME=	nagircbot
PORTVERSION=	0.0.33
PORTREVISION=	2
CATEGORIES=	net-mgmt irc
MASTER_SITES=	http://www.vanheusden.com/nagircbot/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC bot for Nagios

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: pfh
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: pfh

USES=		gmake ssl tar:tgz
USE_RC_SUBR=	nagircbot
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

PLIST_FILES=	bin/nagircbot

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/nagircbot

.include <bsd.port.mk>
