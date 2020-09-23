# Created by: se@freebsd.org
# $FreeBSD$

PORTNAME=	hexpeek
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.20200804
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://www.hexpeek.com/releases/${DISTNAME}/

MAINTAINER=	se@freebsd.org
COMMENT=	Hex file editor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tar:bzip2 libedit ncurses
USE_CSTD=	c99

CFLAGS+=	-Isrc -D_WITH_GETLINE -L${LOCALBASE}/lib

PLIST_FILES=	bin/hexdiff bin/hexDump bin/hexpack bin/hexpeek bin/hexview
PLIST_FILES+=	share/man/man1/hexpeek.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}  ${WRKSRC}/etc/hexpeek.1 ${STAGEDIR}${MANPREFIX}/share/man/man1

.include <bsd.port.mk>
