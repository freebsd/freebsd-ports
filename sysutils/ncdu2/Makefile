PORTNAME=	ncdu
PORTVERSION=	2.2.2
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	https://dev.yorhel.nl/download/
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	NCurses Disk Usage (stable version written in Zig)
WWW=		https://dev.yorhel.nl/ncdu \
		https://code.blicky.net/yorhel/ncdu

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSES/MIT.txt

BUILD_DEPENDS=	zig>=0.10.0<0.10.1_99:lang/zig

USES=		ncurses

BUILD_ARGS=	--prefix "${PREFIX}" --verbose ${STRIP:C|.+|-Dstrip|}
MAKE_ENV=	DESTDIR="${STAGEDIR}"

PLIST_FILES=	bin/ncdu2 \
		share/man/man1/ncdu2.1.gz

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} zig build ${BUILD_ARGS}

do-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/ncdu ${STAGEDIR}${PREFIX}/bin/ncdu2
	${INSTALL_MAN} ${WRKSRC}/ncdu.1 ${STAGEDIR}${PREFIX}/share/man/man1/ncdu2.1

.include <bsd.port.mk>
