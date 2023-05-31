PORTNAME=	ncdu
PORTVERSION=	2.2.2
CATEGORIES=	sysutils
MASTER_SITES=	https://dev.yorhel.nl/download/
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	NCurses Disk Usage (stable version written in Zig)
WWW=		https://dev.yorhel.nl/ncdu

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSES/MIT.txt

BUILD_DEPENDS=	zig>=0.10.0<0.11:lang/zig
RUN_DEPENDS=	zig:lang/zig

USES=		ncurses

BUILD_ARGS=	--prefix "${PREFIX}" --verbose
MAKE_ENV=	DESTDIR="${STAGEDIR}"

PLIST_FILES=	bin/ncdu \
		share/man/man1/ncdu.1.gz

CONFLICTS_INSTALL=	ncdu

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} zig build ${BUILD_ARGS}

do-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ncdu
	${INSTALL_MAN} ${WRKSRC}/ncdu.1 ${STAGEDIR}${PREFIX}/share/man/man1/ncdu.1

.include <bsd.port.mk>
