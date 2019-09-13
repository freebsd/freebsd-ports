# $FreeBSD$

PORTNAME=	epson-inkjet-printer-escpr
PORTVERSION=	1.7.3
DISTVERSIONSUFFIX=	-1lsb3.2
CATEGORIES=	print
MASTER_SITES=	https://download3.ebz.epson.net/dsc/f/03/00/09/83/26/f90d0f70b33a9d7d77a2408364c47fba1ccbf943/

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Epson Inkjet Printer Driver (ESC/P-R) for Linux

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcupsimage.so:print/cups

USES=		autoreconf dos2unix gmake libtool
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS NEWS README README.ja
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-lsb
INSTALL_TARGET=	install-strip
SUB_FILES=	pkg-message
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

PORTSCOUT=	ignore	# MASTER_SITES is changed in each version

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
