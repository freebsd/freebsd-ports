# Created by: Jason Helfman <jgh@FreeBSD.org>

PORTNAME=	virt-viewer
PORTVERSION=	11.0
CATEGORIES=	net-mgmt
MASTER_SITES=	https://virt-manager.org/download/sources/${PORTNAME}/

PATCH_SITES=	https://gitlab.com/${PORTNAME}/${PORTNAME}/-/commit/
PATCHFILES+=	41cc016278e7.patch:-p1 # https://gitlab.com/virt-viewer/virt-viewer/-/merge_requests/117

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Provides a graphical viewer for a guest OS display

LICENSE=	GPLv2

USES=		cpe desktop-file-utils gettext gettext-tools gmake gnome \
		libtool meson perl5 pkgconfig python:3.6+,build \
		shared-mime-info tar:xz xorg
CPE_VENDOR=	redhat
USE_GNOME=	gtk30 libxml2
USE_PERL5=	build # pod2man
USE_XORG=	xorgproto
BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=	SPICE VNC LIBVIRT VTE
OPTIONS_DEFAULT=	SPICE VNC LIBVIRT VTE
OPTIONS_SUB=	yes

SPICE_DESC=	SPICE support
VNC_DESC=	VNC support
VTE_DESC=	VTE support

LIBVIRT_LIB_DEPENDS=	libvirt.so:devel/libvirt \
			libvirt-glib-1.0.so:devel/libvirt-glib
LIBVIRT_MESON_ENABLED=	libvirt

SPICE_BUILD_DEPENDS=	spice-protocol>=0.12.7:devel/spice-protocol
SPICE_LIB_DEPENDS=	libspice-client-glib-2.0.so:deskutils/spice-gtk
SPICE_MESON_ENABLED=	spice

VNC_LIB_DEPENDS=	libgtk-vnc-2.0.so:net/gtk-vnc
VNC_MESON_ENABLED=	vnc

VTE_USE=		GNOME=vte3
VTE_MESON_ENABLED=	vte

.include <bsd.port.mk>
