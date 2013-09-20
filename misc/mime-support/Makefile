# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	mime-support
PORTVERSION=	3.54
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION:C/([0-9]*\.[0-9]*)\.(.*)/\1-\2/}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	MIME Media Types list

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\.2$//}

NO_BUILD=	yes
PLIST_FILES=	bin/run-mailcap etc/mime.types
MAN1=		run-mailcap.1

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/run-mailcap ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mime.types ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/run-mailcap.man ${MANPREFIX}/man/man1/run-mailcap.1

.include <bsd.port.mk>
