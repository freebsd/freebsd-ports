# New ports collection makefile for: virt-viewer
# Date created:    2011-06-07
# Whom:      Jason Helfman <jhelfman@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	virt-viewer
PORTVERSION=	0.4.1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://virt-manager.org/download/sources/${PORTNAME}/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Provides a graphical viewer for a guest OS display

BUILD_DEPENDS=	xml2-config:${PORTSDIR}/textproc/libxml2 \
		intltoolize:${PORTSDIR}/textproc/intltool
LIB_DEPENDS=	virt.9:${PORTSDIR}/devel/libvirt \
		gtk-vnc-1.0.0:${PORTSDIR}/net/gtk-vnc

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	DATADIRNAME=share
USE_GMAKE=	yes
PLIST_SUB=	NLS=""

MAN1=		virt-viewer.1

.include <bsd.port.mk>
