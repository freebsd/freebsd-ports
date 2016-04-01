# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	flashrom
PORTVERSION=	0.9.9
CATEGORIES=	sysutils
MASTER_SITES=	http://download.flashrom.org/releases/

MAINTAINER=	nukama+maintainer@gmail.com
COMMENT=	Utility for reading, writing, verifying, and erasing flash ROM chips

LICENSE=	GPLv2

LIB_DEPENDS=	libpci.so:devel/libpci

OPTIONS_DEFINE=		BUSPIRATE DMIDECODE DOCS FTDI
OPTIONS_DEFAULT=	DMIDECODE FTDI

BUSPIRATE_DESC=		Enable buspirate support (broken)
DMIDECODE_DESC=		Use dmidecode to gather DMI information
FTDI_DESC=		Enable external FT2232SPI flasher support

USES=		gmake tar:bzip2
MAKE_ENV=	CONFIG_BUSPIRATE_SPI=no \
		WARNERROR=no

ONLY_FOR_ARCHS=	amd64 i386

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	ChangeLog README

DOCSRCDIR2=	${WRKSRC}/Documentation
DOCSDIR2=	${DOCSDIR}/Documentation
DOC_FILES2=	*.txt

PLIST_FILES=	bin/${PORTNAME} \
		man/man8/${PORTNAME}.8.gz

BUSPIRATE_MAKE_ENV=	CONFIG_BUSPIRATE_SPI=yes

DMIDECODE_RUN_DEPENDS+=	dmidecode:sysutils/dmidecode

FTDI_LIB_DEPENDS=	libftdi1.so:devel/libftdi1
FTDI_USES=		pkgconfig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
