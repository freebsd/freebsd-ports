# New ports collection makefile for:	libcmis
# Date created:		2012-01-22
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libcmis
PORTVERSION=	0.1.0
CATEGORIES=	net devel
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Client library for the CMIS interface

LICENSE=	LGPL20 MPL GPLv2
LICENSE_COMB=	dual

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	${LOCALBASE}/lib/libcppunit.so:${PORTSDIR}/devel/cppunit \
		${LOCALBASE}/lib/libboost_regex.a:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
USE_GNOME=	libxml2 gnomehack
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
