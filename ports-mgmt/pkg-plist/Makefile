# Created by: Martin Tournoij <martin@arp242.net>
# $FreeBSD$

PORTNAME=	pkg-plist
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	ports-mgmt python
MASTER_SITES=	http://code.arp242.net/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Generate a pkg-plist for a port

LICENSE=	MIT

USES=		python:run shebangfix
SHEBANG_FILES=	pkg-plist
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

BB_ACCOUNT=	Carpetsmoker
BB_PROJECT=	${PORTNAME}
BB_COMMIT=	ff040a64c20b

NO_ARCH=	yes

PLIST_FILES=	bin/pkg-plist man/man1/pkg-plist.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg-plist ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pkg-plist.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
