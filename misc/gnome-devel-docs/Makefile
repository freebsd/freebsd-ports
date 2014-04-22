# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/misc/gnome-devel-docs/Makefile,v 1.22 2010/09/29 15:17:53 kwm Exp $

PORTNAME=	gnome-devel-docs
PORTVERSION=	2.32.0
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Documents targeted for GNOME developers

BUILD_DEPENDS=	gnome-doc-prepare:${PORTSDIR}/textproc/gnome-doc-utils
RUN_DEPENDS=	gnome-doc-prepare:${PORTSDIR}/textproc/gnome-doc-utils

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig tar:bzip2
USE_GNOME=	gnomehier
INSTALLS_OMF=	yes

.include <bsd.port.mk>
