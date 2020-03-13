# Created by: ijliao
# $FreeBSD$

PORTNAME=	raptor2
PORTVERSION=	2.0.15
PORTREVISION=	13
CATEGORIES=	textproc
MASTER_SITES=	http://download.librdf.org/source/ \
		SF/librdf/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	RDF Parser Toolkit for Redland

# Even though GPLv3 is not explicitly mentioned in the port's LICENSE.html, one
# of its licenses is "GPLv2 or newer", which includes GPLv3.
LICENSE=	APACHE20 GPLv2 GPLv3 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libicuuc.so:devel/icu \
		libyajl.so:devel/yajl

CONFLICTS=	raptor-1.4.1[0-9]* raptor-1.4.21

USE_GNOME=	libxml2 libxslt
USES=		gnome libtool:keepla pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xml2-config=${LOCALBASE}/bin/xml2-config \
		--with-curl-config=${LOCALBASE}/bin/curl-config \
		--with-icu-config=${LOCALBASE}/bin/icu-config \
		--with-www=curl
INSTALL_TARGET=	install-strip

USE_LDCONFIG=	yes

.include <bsd.port.mk>
