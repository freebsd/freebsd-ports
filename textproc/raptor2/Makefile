# New ports collection makefile for:	raptor
# Date created:			Nov 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	raptor2
PORTVERSION=	2.0.4
CATEGORIES=	textproc
MASTER_SITES=	http://download.librdf.org/source/ \
		SF/librdf/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	RDF Parser Toolkit for Redland

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		yajl.1:${PORTSDIR}/devel/yajl

CONFLICTS=	raptor-1.4.1[0-9]* raptor-1.4.21

USE_GNOME=	gnomehack libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xml2-config=${LOCALBASE}/bin/xml2-config \
		--with-curl-config=${LOCALBASE}/bin/curl-config \
		--with-pkg-config=${LOCALBASE}/bin/pkg-config \
		--with-xml-parser=libxml --with-www=curl

USE_LDCONFIG=	yes

MAN1=		rapper.1
MAN3=		libraptor2.3

.include <bsd.port.mk>
