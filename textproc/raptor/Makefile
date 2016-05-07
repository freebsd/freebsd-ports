# Created by: ijliao
# $FreeBSD$

PORTNAME=	raptor
PORTVERSION=	1.4.21
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	SF/librdf/${PORTNAME}/${PORTVERSION} \
		http://download.librdf.org/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RDF Parser Toolkit for Redland

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		libtool pathfix
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xml2-config=${LOCALBASE}/bin/xml2-config \
		--with-curl-config=${LOCALBASE}/bin/curl-config \
		--with-html-dir=${PREFIX}/share/doc \
		--with-xml-parser=libxml --with-www=curl
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|utils ||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
