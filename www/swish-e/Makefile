# New ports collection makefile for:    swish-e
# Date created:         		23 Feb 98
# Whom:              			Daniel O'Connor <doconnor@gsoft.com.au>
#
# $FreeBSD$
#

PORTNAME=	swish-e
PORTVERSION=	2.4.3
CATEGORIES=	www textproc
MASTER_SITES=	http://swish-e.org/distribution/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple web indexing for humans - enhanced

USE_GNOME=	libxml2
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

PORTDOCS=	*

MAN1=	SWISH-CONFIG.1 SWISH-FAQ.1 SWISH-LIBRARY.1 SWISH-RUN.1 swish-e.1

.include <bsd.port.mk>
