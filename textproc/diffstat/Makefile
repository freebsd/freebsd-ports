# Created by: trevor
# $FreeBSD$

PORTNAME=	diffstat
PORTVERSION=	1.61
CATEGORIES=	textproc devel
MASTER_SITES=	ftp://invisible-island.net/${PORTNAME}/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Makes a histogram summarizing "diff" output

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:tgz
GNU_CONFIGURE=	yes
MAKEFILE=	makefile

PLIST_FILES=	bin/diffstat man/man1/diffstat.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
