# Created by: se@freebsd.org
# $FreeBSD$

PORTNAME=	hexpeek
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.20200804
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	https://www.hexpeek.com/releases/${DISTNAME}/

MAINTAINER=	se@freebsd.org
COMMENT=	Hex file editor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libedit ncurses tar:bzip2
USE_CSTD=	c99

CFLAGS+=	-D_WITH_GETLINE -Isrc -L${LOCALBASE}/lib

PLIST_FILES=	bin/hexdiff \
		bin/hexDump \
		bin/hexpack \
		bin/hexpeek \
		bin/hexview \
		share/man/man1/hexpeek.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}  ${WRKSRC}/etc/hexpeek.1 ${STAGEDIR}${MANPREFIX}/share/man/man1

do-test:
	${MAKE} -C ${WRKSRC}/test test

.include <bsd.port.mk>
