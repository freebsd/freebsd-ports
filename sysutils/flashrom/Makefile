# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	flashrom
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	https://download.flashrom.org/releases/

MAINTAINER=	mizhka@gmail.com
COMMENT=	Utility for reading, writing, verifying, and erasing flash ROM chips

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libpci.so:devel/libpci

USES=		gmake tar:bzip2
MAKE_ENV=	CONFIG_BUSPIRATE_SPI=no \
		WARNERROR=no

PLIST_FILES=	bin/flashrom \
		man/man8/flashrom.8.gz
PORTDOCS=	*

OPTIONS_DEFINE=		BUSPIRATE DMIDECODE DOCS FTDI
OPTIONS_DEFAULT=	DMIDECODE FTDI

BUSPIRATE_DESC=		Enable buspirate support (broken)
DMIDECODE_DESC=		Use dmidecode to gather DMI information
FTDI_DESC=		Enable external FT2232SPI flasher support

BUSPIRATE_MAKE_ENV=	CONFIG_BUSPIRATE_SPI=yes

DMIDECODE_RUN_DEPENDS+=	dmidecode:sysutils/dmidecode

FTDI_LIB_DEPENDS=	libftdi1.so:devel/libftdi1
FTDI_USES=		pkgconfig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flashrom ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/flashrom.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/Documentation && ${INSTALL_DATA} *.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
