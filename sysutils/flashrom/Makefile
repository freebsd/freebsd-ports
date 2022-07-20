PORTNAME=	flashrom
PORTVERSION=	1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
MASTER_SITES=	https://download.flashrom.org/releases/

MAINTAINER=	mizhka@gmail.com
COMMENT=	Utility for reading, writing, verifying, and erasing flash ROM chips

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=	aarch64 riscv64
NOT_FOR_ARCHS_REASON=	Unable to determine endianness.

LIB_DEPENDS=	libpci.so:devel/libpci

USES=		gmake tar:bzip2

MAKE_ENV=	WARNERROR=no

PLIST_FILES=	bin/flashrom \
		man/man8/flashrom.8.gz
PORTDOCS=	*

OPTIONS_DEFINE=	BUSPIRATE DOCS FTDI
OPTIONS_DEFINE_amd64=	DMIDECODE
OPTIONS_DEFINE_i386=	DMIDECODE
OPTIONS_DEFAULT_amd64=	DMIDECODE
OPTIONS_DEFAULT_i386=	DMIDECODE

DMIDECODE_DESC=	Use dmidecode to gather DMI information
FTDI_DESC=	Enable external FT2232SPI flasher support

DMIDECODE_RUN_DEPENDS=	dmidecode:sysutils/dmidecode

FTDI_LIB_DEPENDS=	libftdi1.so:devel/libftdi1
FTDI_USES=		pkgconfig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flashrom ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flashrom.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/Documentation && ${INSTALL_DATA} *.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
