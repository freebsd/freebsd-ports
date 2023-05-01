PORTNAME=	nagircbot
PORTVERSION=	0.0.33
PORTREVISION=	2
CATEGORIES=	net-mgmt irc
MASTER_SITES=	http://www.vanheusden.com/nagircbot/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC bot for Nagios
WWW=		http://www.vanheusden.com/nagircbot/

DEPRECATED=	Broken for more than a year and fails to build on all supported release
EXPIRATION_DATE=	2023-06-01
BROKEN=	ld: error: duplicate symbol: pfh

USES=		gmake ssl tar:tgz
USE_RC_SUBR=	nagircbot
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

PLIST_FILES=	bin/nagircbot

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/nagircbot

.include <bsd.port.mk>
