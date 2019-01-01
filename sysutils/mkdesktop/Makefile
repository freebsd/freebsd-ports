# $FreeBSD$

PORTNAME=	mkdesktop
PORTVERSION=	3.0
CATEGORIES=	sysutils

MAINTAINER=	bourne.identity@hotmail.com
COMMENT=	Powerful, flexible utility to setup a FreeBSD desktop

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_BUILD=	yes
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	bourne-again

PLIST_FILES=	bin/mkdesktop \
		share/mkdesktop/stage-definitions \
		man/man1/mkdesktop.1.gz

do-install:
		${MKDIR} ${STAGEDIR}${DATADIR}
		${INSTALL_DATA} ${WRKSRC}/stage-definitions ${STAGEDIR}${DATADIR}
		${INSTALL_SCRIPT} ${WRKSRC}/mkdesktop ${STAGEDIR}${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/mkdesktop.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
