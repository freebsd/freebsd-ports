# New ports collection makefile for:	xfce4-fsguard-plugin
# Date created:		2003-12-20
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-fsguard-plugin
PORTVERSION=	0.3.0
CATEGORIES=	sysutils xfce
MASTER_SITES=	http://download.berlios.de/xfce-goodies/ \
		http://ftp.lug.udel.edu/pub/NetBSD/packages/distfiles/ \
		http://ftp.citkit.ru/pub/NetBSD/packages/distfiles/ \
		${MASTER_SITES_NETBSD}
DIST_SUBDIR=	xfce4
PATCH_SITES=	http://people.freebsd.org/~oliver/xfce/
PATCHFILES=	gcc295-xfce4-fsguard-plugin.patch

MAINTAINER=	jfb@minet.net
COMMENT=	XFce4 panel plugin to check a mountpoint for free disk space

BROKEN=		Unfetchable

GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel
USE_XLIB=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11-wm/xfce4/bsd.xfce.mk"
.include <bsd.port.post.mk>
