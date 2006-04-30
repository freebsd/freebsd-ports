# New ports collection makefile for:   synce-trayicon
# Date created:                28 August 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	synce-trayicon
PORTVERSION=	0.9.0
PORTREVISION=	4
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	synce

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME tray icon showing battery and storage status of a WinCE device

BUILD_DEPENDS=	${X11BASE}/lib/gnome-vfs-2.0/modules/libsyncevfs.so:${PORTSDIR}/palm/synce-gnomevfs
RUN_DEPENDS=	${X11BASE}/lib/gnome-vfs-2.0/modules/libsyncevfs.so:${PORTSDIR}/palm/synce-gnomevfs
LIB_DEPENDS=	gtop-2.0.7:${PORTSDIR}/devel/libgtop2

USE_GMAKE=	yes
USE_GNOME=	libgnomeui gnometarget
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ARGS+=	--with-libsynce=${LOCALBASE} \
			--with-librapi2=${LOCALBASE}

.include <bsd.port.mk>
