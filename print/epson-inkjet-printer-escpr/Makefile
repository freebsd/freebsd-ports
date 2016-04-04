# $FreeBSD$

PORTNAME=	epson-inkjet-printer-escpr
PORTVERSION=	1.6.4
DISTVERSIONSUFFIX=	-1lsb3.2
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	LOCAL/hrs

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Epson Inkjet Printer Driver (ESC/P-R) for Linux

LICENSE=	GPLv2

LIB_DEPENDS=	libcupsimage.so:print/cups

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
