# $FreeBSD$

PORTNAME=	hextools
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://avl.enemy.org/utils/hextools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Useful tools for dealing with hex files

LICENSE=	HEXTOOLS
LICENSE_NAME=	License of hextools
LICENSE_FILE=	${WRKDIR}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/hex2bin bin/bin2hex man/man1/bin2hex.1.gz man/man1/hex2bin.1.gz
ALL_TARGET=	build

post-extract:
	@${SED} -n '5,11p' ${WRKSRC}/hex2bin.c > ${WRKDIR}/LICENSE

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hex2bin ${STAGEDIR}${PREFIX}/bin/hex2bin
	${INSTALL_PROGRAM} ${WRKSRC}/hexdump ${STAGEDIR}${PREFIX}/bin/bin2hex
	${INSTALL_MAN} ${WRKSRC}/hex2bin.1 ${STAGEDIR}${MANPREFIX}/man/man1/hex2bin.1
	${INSTALL_MAN} ${WRKSRC}/hexdump.1 ${STAGEDIR}${MANPREFIX}/man/man1/bin2hex.1

.include <bsd.port.mk>
