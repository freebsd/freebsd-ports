# Created by: ijliao
# $FreeBSD$

PORTNAME=	raptor2
PORTVERSION=	2.0.9
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://download.librdf.org/source/ \
		SF/librdf/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	RDF Parser Toolkit for Redland

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		icuuc:${PORTSDIR}/devel/icu \
		yajl:${PORTSDIR}/devel/yajl

CONFLICTS=	raptor-1.4.1[0-9]* raptor-1.4.21

USE_GNOME=	libxml2 libxslt
USES=		pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xml2-config=${LOCALBASE}/bin/xml2-config \
		--with-curl-config=${LOCALBASE}/bin/curl-config \
		--with-pkg-config=${LOCALBASE}/bin/pkg-config \
		--with-icu-config=${LOCALBASE}/bin/icu-config \
		--with-www=curl

USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		rapper.1
MAN3=		libraptor2.3

.include <bsd.port.mk>
