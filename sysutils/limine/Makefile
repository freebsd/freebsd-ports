PORTNAME=	limine
DISTVERSION=	6.20231227.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/${PORTNAME}-bootloader/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	mintsuki@protonmail.com
COMMENT=	Modern, advanced, portable, multiprotocol bootloader
WWW=		https://limine-bootloader.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	mtools:emulators/mtools \
		nasm:devel/nasm

USES=		gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-all
MAKEFILE=	GNUmakefile

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
