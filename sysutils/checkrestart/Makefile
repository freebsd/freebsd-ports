# $FreeBSD$

PORTNAME=	checkrestart
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	sysutils

MAINTAINER=	tom@hur.st
COMMENT=	Find processes that need restarting after an upgrade

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	Freaky

SUB_FILES=	checkrestart

PLIST_FILES=	bin/checkrestart \
		share/man/man1/checkrestart.1.gz \
		etc/periodic/daily/checkrestart

PERIODIC_DAILY=	etc/periodic/daily

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/checkrestart ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/checkrestart.1 ${STAGEDIR}${MAN1PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PERIODIC_DAILY}
	${INSTALL_SCRIPT} ${WRKDIR}/checkrestart ${STAGEDIR}${PREFIX}/${PERIODIC_DAILY}

.include <bsd.port.mk>
