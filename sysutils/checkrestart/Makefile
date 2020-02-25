# $FreeBSD$

PORTNAME=	checkrestart
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	sysutils

MAINTAINER=	tom@hur.st
COMMENT=	Find processes that need restarting after an upgrade

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	Freaky

PLIST_FILES=	bin/checkrestart \
		share/man/man1/checkrestart.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/checkrestart ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/checkrestart.1 ${STAGEDIR}${MAN1PREFIX}/share/man/man1

.include <bsd.port.mk>
