PORTNAME=	limine
DISTVERSION=	7.13.2
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

PORTDOCS=	CONFIG.md PHILOSOPHY.md PROTOCOL.md USAGE.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/COPYING/d' ${WRKSRC}/GNUmakefile.in

.include <bsd.port.mk>
