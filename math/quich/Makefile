PORTNAME=	quich
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.0
CATEGORIES=	math

PATCH_SITES=	https://github.com/Usbac/quich/commit/
PATCHFILES=	9ddb21a370fe403b6863995f1f2225529a5f0f81.patch:-p1

MAINTAINER=	tiago.gasiba@gmail.com
COMMENT=	Just an advanced terminal calculator
WWW=		https://github.com/Usbac/quich

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	liblinenoise.so:devel/linenoise

USES=		cmake compiler:c++11-lib pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	Usbac

CMAKE_ON=	CMAKE_SKIP_RPATH

PLIST_FILES=	bin/quich

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/quich ${STAGEDIR}${PREFIX}/bin/

do-test:
	cd ${WRKDIR}/.build && ./quich_test

.include <bsd.port.mk>
