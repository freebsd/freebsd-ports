# New ports collection makefile for:	raptor
# Date created:			Nov 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	raptor
PORTVERSION=	1.4.21
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/librdf/${PORTNAME}/${PORTVERSION} \
		http://download.librdf.org/source/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	RDF Parser Toolkit for Redland

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

USE_GNOME=	gnomehack libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xml2-config=${LOCALBASE}/bin/xml2-config \
		--with-curl-config=${LOCALBASE}/bin/curl-config \
		--with-pkg-config=${LOCALBASE}/bin/pkg-config \
		--with-xml-parser=libxml --with-www=curl
CONFIGURE_ENV+=	DOC_MODULE_VERSION=1
MAKE_ENV+=	DOC_MODULE_VERSION=1

USE_LDCONFIG=	yes

MAN1=		raptor-config.1
MAN3=		libraptor.3

post-extract:
	${REINPLACE_CMD} -e 's|utils ||' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
