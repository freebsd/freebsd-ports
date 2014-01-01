# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flickcurl
PORTVERSION=	1.25
CATEGORIES=	www
MASTER_SITES=	http://download.dajobe.org/flickcurl/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	C library for the Flickr API

LICENSE=	APACHE20 GPLv2 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

OPTIONS_DEFINE=	RAPTOR DOCS
OPTIONS_RADIO=	WEBSERVICE
OPTIONS_RADIO_WEBSERVICE=	OFFLINE CAPTURE
OPTIONS_DEFAULT=RAPTOR
RAPTOR_DESC=	Use Raptor to serialize to triples
OFFLINE_DESC=	Offline use of captured XML web service responses
CAPTURE_DESC=	Capturing web service responses

USES=		pathfix pkgconfig
USE_GNOME=	ltverhack libxml2
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
USE_LDCONFIG=	yes

OFFLINE_CONFIGURE_ON=		--enable-offline
OFFLINE_CONFIGURE_OFF=		offline=no
CAPTURE_CONFIGURE_ON=		--enable-capture
CAPTURE_CONFIGURE_OFF=		capture=no
RAPTOR_LIB_DEPENDS=		libraptor2.so:${PORTSDIR}/textproc/raptor2
RAPTOR_CONFIGURE_ON=		--with-raptor=2
RAPTOR_CONFIGURE_OFF=		--with-raptor=no

.include <bsd.port.mk>
