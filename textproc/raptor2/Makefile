# ex:ts=8
# New ports collection makefile for:	raptor
# Date created:			Nov 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	raptor
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.redland.opensource.ac.uk/dist/source/
MASTER_SITE_SUBDIR=	librdf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RDF Parser Toolkit for Redland

LIB_DEPENDS=	curl.2:${PORTSDIR}/ftp/curl \
		xmlparse.1:${PORTSDIR}/www/libwww

USE_GETOPT_LONG=	yes
USE_GNOME=	glib20 gnomehack gnometarget libxml2 lthack
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-xml2-config=${LOCALBASE}/bin/xml2-config \
		--with-curl-config=${LOCALBASE}/bin/curl-config \
		--with-libwww-config=${LOCALBASE}/bin/libwww-config \
		--with-pkg-config=${LOCALBASE}/bin/pkg-config \
		--with-xml-parser=libxml
INSTALLS_SHLIB=	yes

MAN1=		rapper.1 raptor-config.1
MAN3=		libraptor.3

.include <bsd.port.mk>
