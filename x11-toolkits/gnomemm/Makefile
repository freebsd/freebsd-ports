# New ports collection makefile for:    gnomemm
# Date created:         21 May 2003
# Whom:                 Alexander Nedotsukov <bland@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	gnomemm
PORTVERSION=	1.3.17
PORTREVISION=	3
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=   # empty
DISTFILES=      # empty
EXTRACT_ONLY=   # empty

MAINTAINER=	bland@FreeBSD.org
COMMENT=	The "meta-port" for the powerful C++ bindings to the GNOME2 libraries

LIB_DEPENDS=	gconfmm-2.0:${PORTSDIR}/devel/gconfmm \
		gnomevfsmm-1.3:${PORTSDIR}/devel/gnome-vfsmm \
		bonobomm_servers-1.3:${PORTSDIR}/devel/libbonobomm \
		bonobouimm_servers-1.3:${PORTSDIR}/x11-toolkits/libbonobouimm \
		glademm-2.0:${PORTSDIR}/devel/libglademm \
		gnomecanvasmm-2.0:${PORTSDIR}/graphics/libgnomecanvasmm \
		gnomemm-2.0:${PORTSDIR}/x11/libgnomemm \
		gnomeuimm-2.0:${PORTSDIR}/x11-toolkits/libgnomeuimm

NO_BUILD=	yes
LATEST_LINK=	gnomemm2

do-install:     # empty

.include <bsd.port.mk>
