PORTNAME=	flashrom
PORTVERSION=	1.3.0
DISTVERSIONPREFIX=	v
PORTREVISION=   1
CATEGORIES=	sysutils
MASTER_SITES=	https://download.flashrom.org/releases/

MAINTAINER=	mizhka@FreeBSD.org
COMMENT=	Utility for reading, writing, verifying, and erasing flash ROM chips
WWW=		https://www.flashrom.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=	aarch64 riscv64
NOT_FOR_ARCHS_REASON=	Unable to determine endianness.

BUILD_DEPENDS+=	cmocka>=0:sysutils/cmocka
LIB_DEPENDS=	libpci.so:devel/libpci

USES=		meson pkgconfig tar:bzip2

PORTDOCS=	*

OPTIONS_DEFINE= DOCS FTDI
OPTIONS_DEFINE_amd64=	DMIDECODE
OPTIONS_DEFINE_i386=	DMIDECODE
OPTIONS_DEFAULT_amd64=	DMIDECODE
OPTIONS_DEFAULT_i386=	DMIDECODE

DMIDECODE_DESC=	Use dmidecode to gather DMI information
FTDI_DESC=	Enable external FT2232SPI flasher support

DMIDECODE_RUN_DEPENDS=	dmidecode:sysutils/dmidecode

FTDI_LIB_DEPENDS=	libftdi1.so:devel/libftdi1

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/Documentation && ${INSTALL_DATA} *.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
