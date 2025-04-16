PORTNAME=	slst
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.vanheusden.com/slst/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates syslog statistics to detect tendencies and unexpected change
WWW=		http://www.vanheusden.com/slst/

DEPRECATED=     No source. Source went missing in 2018.
EXPIRATION_DATE=2025-05-15

USES=		ncurses tar:tgz
ALL_TARGET=	all

PLIST_FILES=	bin/slst

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/slst

.include <bsd.port.mk>
