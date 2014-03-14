# Created by: David O'Brien (obrien@NUXI.com)
# $FreeBSD$

PORTNAME=	vnconvert
PORTVERSION=	1.0
CATEGORIES=	vietnamese
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	obrien
DISTNAME=	convert
EXTRACT_SUFX=	.tar

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	Converts Vietnamese text files between popular formats

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=

PLIST_FILES=	bin/vnconvert man/man1/vnconvert.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vnconvert ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/vnconvert.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
