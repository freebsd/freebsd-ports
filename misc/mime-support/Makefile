# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD: head/misc/mime-support/Makefile 357611 2014-06-12 16:03:01Z oliver $

PORTNAME=	mime-support
PORTVERSION=	3.58
CATEGORIES=	misc
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION:C/([0-9]*\.[0-9]*)\.(.*)/\1-\2/}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	MIME Media Types list

USES=		cpe shebangfix

CPE_VENDOR=	debian

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\.2$//}

NO_BUILD=	yes
PLIST_FILES=	bin/run-mailcap etc/mime.types \
		man/man1/run-mailcap.1.gz

SHEBANG_FILES=	run-mailcap

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/run-mailcap ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mime.types ${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/run-mailcap.man ${STAGEDIR}${MANPREFIX}/man/man1/run-mailcap.1

.include <bsd.port.mk>
