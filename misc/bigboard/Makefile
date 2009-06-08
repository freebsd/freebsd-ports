# New ports collection makefile for:	bigboard
# Date created:		2008-05-28
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bigboard
PORTVERSION=	0.5.38
PORTREVISION=	1
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME

MAINTAINER=	wahjava@gmail.com
COMMENT=	Big Board sidebar is an experimental panel for the GNOME Desktop

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-1.pc:${PORTSDIR}/devel/dbus \
		${LOCALBASE}/libdata/pkgconfig/gnome-keyring-1.pc:${PORTSDIR}/security/gnome-keyring \
		${LOCALBASE}/libdata/pkgconfig/libsoup-2.4.pc:${PORTSDIR}/devel/libsoup \
		${LOCALBASE}/libdata/pkgconfig/hippo-canvas-1.pc:${PORTSDIR}/x11-toolkits/hippo-canvas \
		${LOCALBASE}/libdata/pkgconfig/ddm-1.pc:${PORTSDIR}/net/desktop-data-model \
		${LOCALBASE}/libdata/pkgconfig/gnome-python-2.0.pc:${PORTSDIR}/x11-toolkits/py-gnome2 \
		${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus
LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus \
		gnome-keyring.0:${PORTSDIR}/security/gnome-keyring \
		soup-2.4.1:${PORTSDIR}/devel/libsoup \
		hippocanvas-1.0:${PORTSDIR}/x11-toolkits/hippo-canvas
RUN_DEPENDS=	${LOCALBASE}/libexec/desktop-data-engine:${PORTSDIR}/net/desktop-data-model \
		${LOCALBASE}/libdata/pkgconfig/gnome-python-2.0.pc:${PORTSDIR}/x11-toolkits/py-gnome2 \
		${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus

USE_GMAKE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	2.5+
USE_GNOME=	pygtk2 gtk20 gnomevfs2 gnomedesktop gnomepanel gconf2 pygnome2 gnomehack
GCONF_SCHEMAS=	bigboard.schemas

post-patch:
	@${FIND} ${WRKSRC} -type f -exec fgrep -l '%%LOCALBASE%%' {} \; |${XARGS} ${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' -i .bak

.include <bsd.port.mk>
