# Created by: Alexander Nedotsukov <bland@mail.ru>
# $FreeBSD$

PORTNAME=	gnomemm
PORTVERSION=	2.6.2
PORTREVISION=	8
CATEGORIES=	x11-toolkits devel gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	bland@FreeBSD.org
COMMENT=	The "meta-port" for the powerful C++ bindings to the GNOME2 libraries

LIB_DEPENDS=	libgconfmm-2.6.so:${PORTSDIR}/devel/gconfmm26 \
		libgnomevfsmm-2.6.so:${PORTSDIR}/devel/gnome-vfsmm \
		libglademm-2.4.so:${PORTSDIR}/devel/libglademm24 \
		libgnomecanvasmm-2.6.so:${PORTSDIR}/graphics/libgnomecanvasmm26 \
		libgnomemm-2.6.so:${PORTSDIR}/x11/libgnomemm26 \
		libgnomeuimm-2.6.so:${PORTSDIR}/x11-toolkits/libgnomeuimm26

NO_BUILD=	yes
NO_INSTALL=	yes
NO_MTREE=	yes

.include <bsd.port.mk>
