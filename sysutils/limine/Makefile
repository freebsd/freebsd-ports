PORTNAME=	limine
DISTVERSION=	9.6.1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/${PORTNAME}-bootloader/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	mintsuki@protonmail.com
COMMENT=	Modern, advanced, portable, multiprotocol bootloader and boot manager
WWW=		https://limine-bootloader.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	mtools:filesystems/mtools \
		nasm:devel/nasm

USES=		gmake
GNU_CONFIGURE=	yes

# Disable the loongarch64 port as the LLVM target for it is still not enabled
# everywhere.
CONFIGURE_ARGS=	--enable-all --disable-uefi-loongarch64
MAKEFILE=	GNUmakefile

INSTALL_TARGET=	install-strip

PORTDOCS=	3RDPARTY.md CONFIG.md FAQ.md PROTOCOL.md USAGE.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/COPYING/d' ${WRKSRC}/GNUmakefile.in
	@${REINPLACE_CMD} -e '/LICENSES/d' ${WRKSRC}/GNUmakefile.in

.include <bsd.port.mk>
