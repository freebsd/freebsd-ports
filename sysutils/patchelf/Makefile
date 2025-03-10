PORTNAME=	patchelf
DISTVERSION=	0.18.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/NixOS/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Utility to modify the dynamic linker
WWW=		https://github.com/NixOS/patchelf

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lang gmake tar:bz2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

# tests as of 0.18.0: 2 tests fail, see https://github.com/NixOS/patchelf/issues/584

.include <bsd.port.mk>
