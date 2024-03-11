PORTNAME=	limine
DISTVERSION=	7.0.5
PORTREVISION=	1
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
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CONFIGURE_ARGS=	--enable-all
MAKEFILE=	GNUmakefile

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
