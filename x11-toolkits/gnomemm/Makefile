# New ports collection makefile for:    gnomemm
# Date created:         21 May 2003
# Whom:                 Alexander Nedotsukov <bland@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	gnomemm
PORTVERSION=	2.6.2
PORTREVISION=	2
CATEGORIES=	x11-toolkits devel gnome
MASTER_SITES=   # empty
DISTFILES=      # empty
EXTRACT_ONLY=   # empty

MAINTAINER=	bland@FreeBSD.org
COMMENT=	The "meta-port" for the powerful C++ bindings to the GNOME2 libraries

LIB_DEPENDS=	gconfmm-2.6.1:${PORTSDIR}/devel/gconfmm26 \
		gnomevfsmm-2.6.1:${PORTSDIR}/devel/gnome-vfsmm \
		glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		gnomecanvasmm-2.6.1:${PORTSDIR}/graphics/libgnomecanvasmm26 \
		gnomemm-2.6.1:${PORTSDIR}/x11/libgnomemm26 \
		gnomeuimm-2.6.1:${PORTSDIR}/x11-toolkits/libgnomeuimm26

NO_BUILD=	yes
LATEST_LINK=	gnomemm2

do-install:     # empty

.include <bsd.port.mk>
