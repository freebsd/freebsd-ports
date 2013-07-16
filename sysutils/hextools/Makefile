# $FreeBSD$

PORTNAME=	hextools
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://avl.enemy.org/utils/hextools/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Useful tools for dealing with hex files

NO_WRKSUBDIR=yes

MAN1=		bin2hex.1 hex2bin.1
PLIST_FILES=	bin/hex2bin bin/bin2hex
ALL_TARGET=	build

#not strictly true - it uses a self-styled license
#LICENSE=	BSD

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hex2bin ${PREFIX}/bin/hex2bin
	${INSTALL_PROGRAM} ${WRKSRC}/hexdump ${PREFIX}/bin/bin2hex
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/hex2bin.1 ${MANPREFIX}/man/man1/hex2bin.1
	${INSTALL_MAN} ${WRKSRC}/hexdump.1 ${MANPREFIX}/man/man1/bin2hex.1
.endif

.include <bsd.port.mk>
