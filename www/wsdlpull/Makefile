# Created by: ijliao
# $FreeBSD$

PORTNAME=	wsdlpull
PORTVERSION=	1.24
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ WSDL Parser

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e '/-O2 -Wall/d' ${WRKSRC}/configure
	${REINPLACE_CMD} \
		-e '/SUBDIRS = / s| docs||' \
		-e '/^install-data-am:/ s| install-docsDATA||' \
			${WRKSRC}/Makefile.in
# Do not install wsdlpull-config.1 for the absence of wsdlpull-config
	${REINPLACE_CMD} \
		-e '/^man_MANS = / s| wsdlpull-config.1||' \
			${WRKSRC}/man/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} README wsdlpull.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
