# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flickcurl
PORTVERSION=	1.24
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://download.dajobe.org/flickcurl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library for the Flickr API

LICENSE=	AL2 GPLv2 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

OPTIONS_DEFINE=	RAPTOR DOCS
OPTIONS_DEFAULT=RAPTOR
RAPTOR_DESC=	Use Raptor to serialize to triples

USES=		pathfix pkgconfig
USE_GNOME=	ltverhack libxml2
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-html-dir=${WRKDIR}/tmproot
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		flickcurl.1 flickcurl-config.1 flickrdf.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRAPTOR}
LIB_DEPENDS+=	raptor2:${PORTSDIR}/textproc/raptor2
CONFIGURE_ARGS+=--with-raptor=2
.else
CONFIGURE_ARGS+=--with-raptor=no
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKDIR}/tmproot/flickcurl && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
