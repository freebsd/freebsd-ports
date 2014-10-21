# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	lookout
PORTVERSION=	1.4
CATEGORIES=	mail
MASTER_SITES=	http://catb.org/~esr/lookout/

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Convert Outlook97 addressbook export files to KDE KAB/GNOME gnomecard

USES=		python
NO_BUILD=	yes

PLIST_FILES=	bin/lookout man/man1/lookout.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lookout ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lookout.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
