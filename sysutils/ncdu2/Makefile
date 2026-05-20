PORTNAME=	ncdu
PORTVERSION=	2.9.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://dev.yorhel.nl/download/
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	NCurses Disk Usage (stable version written in Zig)
WWW=		https://dev.yorhel.nl/ncdu \
		https://code.blicky.net/yorhel/ncdu

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSES/MIT.txt

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		ncurses pkgconfig zig:015

ZIG_ARGS=	-Dpie ${STRIP:C|.+|-Dstrip|}

PLIST_FILES=	bin/ncdu2 \
		share/man/man1/ncdu2.1.gz

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/ncdu ${STAGEDIR}${PREFIX}/bin/ncdu2
	${INSTALL_MAN} ${WRKSRC}/ncdu.1 ${STAGEDIR}${PREFIX}/share/man/man1/ncdu2.1

do-test:
	cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} zig build test ${BUILD_ARGS}

.include <bsd.port.mk>
