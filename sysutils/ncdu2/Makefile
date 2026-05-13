PORTNAME=	ncdu
PORTVERSION=	2.9.2
CATEGORIES=	sysutils
MASTER_SITES=	https://dev.yorhel.nl/download/
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	NCurses Disk Usage (stable version written in Zig)
WWW=		https://dev.yorhel.nl/ncdu \
		https://code.blicky.net/yorhel/ncdu

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSES/MIT.txt

BUILD_DEPENDS=	zig015>=0.14<0.16:lang/zig015
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		ncurses pkgconfig

BUILD_ARGS=	--prefix ${PREFIX} --verbose -Dpie ${STRIP:C|.+|-Dstrip|}
MAKE_ENV=	DESTDIR=${STAGEDIR}

PLIST_FILES=	bin/ncdu2 \
		share/man/man1/ncdu2.1.gz

do-build:
	cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} zig build ${BUILD_ARGS}

do-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/ncdu ${STAGEDIR}${PREFIX}/bin/ncdu2
	${INSTALL_MAN} ${WRKSRC}/ncdu.1 ${STAGEDIR}${PREFIX}/share/man/man1/ncdu2.1

do-test:
	cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} zig build test ${BUILD_ARGS}

.include <bsd.port.mk>
