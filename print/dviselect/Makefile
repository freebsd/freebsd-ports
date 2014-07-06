# Created by: jmz
# $FreeBSD$

PORTNAME=	dviselect
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jmz

DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extract pages from DVI files

SCRIPTS_ENV=	CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/dviselect man/man1/dviselect.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dviselect ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dviselect.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
