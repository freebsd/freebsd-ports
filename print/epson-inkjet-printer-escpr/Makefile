PORTNAME=	epson-inkjet-printer-escpr
DISTVERSION=	1.7.9
DISTVERSIONSUFFIX=	-1lsb3.2
CATEGORIES=	print
MASTER_SITES=	https://download3.ebz.epson.net/dsc/f/03/00/12/50/95/322b8d6b915ab85add33d41f04ba5130866aadbe/

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Epson Inkjet Printer Driver (ESC/P-R) for Linux

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/libexec/cups/filter/gstoraster:print/cups-filters
LIB_DEPENDS=	libcupsimage.so:print/cups

USES=		autoreconf dos2unix gmake libtool
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
PORTDOCS=	AUTHORS NEWS README README.ja
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-lsb
INSTALL_TARGET=	install-strip
SUB_FILES=	pkg-message
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

PORTSCOUT=	ignore:1	# MASTER_SITES is changed in each version

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
