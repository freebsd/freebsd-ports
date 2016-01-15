# Created by: Antonio Querubin <tony@lava.net>
# $FreeBSD$

PORTNAME=	dbeacon
PORTVERSION=	0.3.9.1
CATEGORIES=	net
MASTER_SITES=	http://fivebits.net/files/dbeacon/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distributed multicast beacon server

BROKEN=		unfetchable

LICENSE=	GPLv2+

USES=		gmake

PLIST_FILES=	bin/dbeacon man/man1/dbeacon.1.gz
USE_RC_SUBR=	dbeacon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/dbeacon.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
