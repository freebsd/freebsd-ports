# New ports collection makefile for:	gnomeuserdocs2
# Date created:        			07 July 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/misc/gnomeuserdocs2/Makefile,v 1.25 2006/04/13 07:52:36 bland Exp $
#

PORTNAME=	gnomeuserdocs2
PORTVERSION=	2.14.2
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-user-docs/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gnome-user-docs-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 users guide

BUILD_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
RUN_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier gnometarget gnomedocutils

.include <bsd.port.mk>
