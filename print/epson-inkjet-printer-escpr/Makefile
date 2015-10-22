# $FreeBSD$

PORTNAME=	epson-inkjet-printer-escpr
PORTVERSION=	1.6.0
DISTVERSIONSUFFIX=	-1lsb3.2
CATEGORIES=	print
MASTER_SITES=	LOCAL/hrs

MAINTAINER=	tatsuki_makino@hotmail.com
COMMENT=	Epson Inkjet Printer Driver (ESC/P-R) for Linux

LICENSE=	GPLv2

BUILD_DEPENDS=	cups-config:${PORTSDIR}/print/cups-client
LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client\
		libcupsimage.so:${PORTSDIR}/print/cups-image

USES=		autoreconf gmake libtool
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
PORTDOCS=	AUTHORS COPYING NEWS README README.ja

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
