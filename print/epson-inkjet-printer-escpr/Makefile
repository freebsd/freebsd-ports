PORTNAME=	epson-inkjet-printer-escpr
DISTVERSION=	1.8.5
DISTVERSIONSUFFIX=	-1
CATEGORIES=	print
MASTER_SITES=	https://download3.ebz.epson.net/dsc/f/03/00/15/68/89/fbff579f15226ffcc4a16895bd6bce6842277802/

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Epson Inkjet Printer Driver (ESC/P-R) for Linux
WWW=		https://download.ebz.epson.net/dsc/search/01/search/?OSC=LX

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcupsimage.so:print/cups
RUN_DEPENDS=	${LOCALBASE}/libexec/cups/filter/gstoraster:print/cups-filters

USES=		autoreconf:2.69 dos2unix libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-lsb
INSTALL_TARGET=	install-strip
# PORTSCOUT=ignore:1 MASTER_SITES is changed in each version
PORTSCOUT=	ignore:1
SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
PORTDOCS=	AUTHORS NEWS README README.ja

OPTIONS_DEFINE=	DOCS

post-install:
	${FIND} -P -- ${STAGEDIR}${LOCALBASE}/share -ipath \*/${PORTNAME}/\* \
		-type f -iname \*.ppd -exec ${GZIP_CMD} -- {} +

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
