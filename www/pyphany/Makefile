# New ports collection makefile for:	pyphany
# Date created:				28 January 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyphany
PORTVERSION=	0.1.3
CATEGORIES=	www python gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.1
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of Python bindings for Epiphany

BUILD_DEPENDS=	epiphany:${PORTSDIR}/www/epiphany
RUN_DEPENDS=	epiphany:${PORTSDIR}/www/epiphany

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack gnometarget intlhack pygnome2
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION="1.6"

.include <bsd.port.mk>
