PORTNAME=	patchelf
DISTVERSION=	0.19.3
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/NixOS/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Utility to modify the dynamic linker
WWW=		https://github.com/NixOS/patchelf

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lang cpe gmake tar:bz2

CPE_VENDOR=	nixos

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

# tests as of 0.19.2: 3 tests fail, see https://github.com/NixOS/patchelf/issues/584
# 3 test failure are portability issues, not real bugs in patchelf

.include <bsd.port.mk>
