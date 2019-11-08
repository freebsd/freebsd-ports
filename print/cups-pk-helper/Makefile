# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/print/cups-pk-helper/Makefile,v 1.1 2009/12/29 16:01:07 ahze Exp $

PORTNAME=	cups-pk-helper
PORTVERSION=	0.2.6
CATEGORIES=	print
MASTER_SITES=	http://www.freedesktop.org/software/${PORTNAME}/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Helper that makes system-config-printer use PolicyKit

LICENSE=	GPLv2

LIB_DEPENDS=	libcups.so:print/cups \
		libpolkit-gobject-1.so:sysutils/polkit

USE_GNOME=	glib20 intltool
USES=		cpe gettext gmake gnome localbase pkgconfig tar:xz
CPE_VENDOR=	cups-pk-helper_project
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
