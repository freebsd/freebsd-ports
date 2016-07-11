# Created by: Antonios Anastasiadis <antonakis@gmail.com>
# $FreeBSD$

PORTNAME=	xps
PORTVERSION=	0.5.2
CATEGORIES=	ports-mgmt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool that searches the ports tree by various criteria

DEPRECATED=     Does not support pkg(8)
EXPIRATION_DATE=        2016-08-10

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	serpent7776

USES=		python
NO_BUILD=	yes

PLIST_FILES=	bin/xps \
		man/man1/xps.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xps ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xps.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
