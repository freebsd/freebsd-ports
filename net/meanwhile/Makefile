# New ports collection makefile for:	meanwhile
# Date created:		24 June 2004
# Whom:		 	Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	meanwhile
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

PATCH_SITES=	${MASTER_SITE_LOCAL} \
		http://people.FreeBSD.org/~marcus/
PATCH_SITE_SUBDIR=marcus
PATCHFILES=	patch-net_meanwhile-cvs

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Open Source implementation of the Lotus Sametime protocol

USE_GMAKE=	yes
USE_GNOME=	lthack glib20
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=13

.include <bsd.port.mk>
