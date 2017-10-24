# $FreeBSD$

PORTNAME=	epson-inkjet-printer-escpr
PORTVERSION=	1.6.17
DISTVERSIONSUFFIX=	-1lsb3.2
CATEGORIES=	print
MASTER_SITES=	https://download3.ebz.epson.net/dsc/f/03/00/06/66/09/4ac2bf69bb1ddf4a9ad525596615cbb40fe4dad5/

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Epson Inkjet Printer Driver (ESC/P-R) for Linux

LICENSE=	GPLv2+

LIB_DEPENDS=	libcupsimage.so:print/cups
FETCH_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		autoreconf dos2unix gmake libtool
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
SUB_FILES=	pkg-message
PORTDOCS=	AUTHORS COPYING NEWS README README.ja

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
