# ex:ts=8
# New ports collection makefile for:	raptor
# Date created:			Nov 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	raptor
PORTVERSION=	1.4.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://librdf.org/dist/source/
MASTER_SITE_SUBDIR=	librdf

MAINTAINER=	chuck@pkix.net
COMMENT=	RDF Parser Toolkit for Redland

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl

USE_GNOME=	gnomehack gnometarget libxml2
USE_GETOPT_LONG=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ARGS=	--with-xml2-config=${LOCALBASE}/bin/xml2-config \
		--with-curl-config=${LOCALBASE}/bin/curl-config \
		--with-pkg-config=${LOCALBASE}/bin/pkg-config \
		--with-xml-parser=libxml --with-www=curl
INSTALLS_SHLIB=	yes

MAN1=		rapper.1 raptor-config.1
MAN3=		libraptor.3

.include <bsd.port.mk>
