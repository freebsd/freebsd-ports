# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virt-viewer
PORTVERSION=	0.5.7
CATEGORIES=	net-mgmt
MASTER_SITES=	http://virt-manager.org/download/sources/${PORTNAME}/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Provides a graphical viewer for a guest OS display

BUILD_DEPENDS=	xml2-config:${PORTSDIR}/textproc/libxml2 \
		intltoolize:${PORTSDIR}/textproc/intltool
LIB_DEPENDS=	virt.1001:${PORTSDIR}/devel/libvirt \
		gtk-vnc-1.0.0:${PORTSDIR}/net/gtk-vnc

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

FETCH_ARGS=	-Fpr

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	DATADIRNAME=share
USES=		gmake pkgconfig

MAN1=		remote-viewer.1 virt-viewer.1

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

NO_STAGE=	yes
.include <bsd.port.mk>
