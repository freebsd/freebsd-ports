# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flickcurl
PORTVERSION=	1.26
CATEGORIES=	www
MASTER_SITES=	http://download.dajobe.org/flickcurl/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C library for the Flickr API

LICENSE=	APACHE20 GPLv2 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	libcurl.so:ftp/curl

OPTIONS_DEFINE=	RAPTOR DOCS
OPTIONS_RADIO=	WEBSERVICE
OPTIONS_RADIO_WEBSERVICE=	OFFLINE CAPTURE
OPTIONS_DEFAULT=RAPTOR
RAPTOR_DESC=	Use Raptor to serialize to triples
OFFLINE_DESC=	Offline use of captured XML web service responses
CAPTURE_DESC=	Capturing web service responses

USES=		libtool pathfix pkgconfig
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OFFLINE_CONFIGURE_ON=		--enable-offline
OFFLINE_CONFIGURE_OFF=		offline=no
CAPTURE_CONFIGURE_ON=		--enable-capture
CAPTURE_CONFIGURE_OFF=		capture=no
RAPTOR_LIB_DEPENDS=		libraptor2.so:textproc/raptor2
RAPTOR_CONFIGURE_ON=		--with-raptor=2
RAPTOR_CONFIGURE_OFF=		--with-raptor=no

.include <bsd.port.mk>
