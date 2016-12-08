# Created by: ijliao
# $FreeBSD$

PORTNAME=	wsdlpull
PORTVERSION=	1.24
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ WSDL Parser

LICENSE=	LGPL21 # code says LGPL20+ and MIT though
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		libtool localbase
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/-O2 -Wall/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} \
		-e '/SUBDIRS = / s| docs||' \
		-e '/^install-data-am:/ s| install-docsDATA||' \
			${WRKSRC}/Makefile.in
# Do not install wsdlpull-config.1 for the absence of wsdlpull-config
	@${REINPLACE_CMD} \
		-e '/^man_MANS = / s| wsdlpull-config.1||' \
			${WRKSRC}/man/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} README wsdlpull.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
