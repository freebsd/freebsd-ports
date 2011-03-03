# New ports collection makefile for:	xfce4-genmon-plugin
# Date created:		2004-09-12
# Whom:			Matt Lancereau <ports@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-genmon-plugin
PORTVERSION=	3.2
PORTREVISION=	11
CATEGORIES=	sysutils xfce
MASTER_SITES=	CRITICAL/xfce4
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Generic Monitor XFce4 panel plugin

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libutil libgui panel

post-patch:
	@${REINPLACE_CMD} -e 's|--libs "libxfce4panel-1.0"|& "libxfcegui4-1.0"|g; \
		s|--cflags "libxfce4panel-1.0"|& "libxfcegui4-1.0"|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
