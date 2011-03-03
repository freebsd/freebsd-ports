# New ports collection makefile for:	xfce4-places-plugin
# Date created:		2007-03-23
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-places-plugin
PORTVERSION=	1.2.0
PORTREVISION=	6
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A file browser launcher for XFce4 panel plugin

BROKEN=		Does not work with xfce 4.8

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel thunar thunarvfs

# exo_url_show function is still missing
#post-patch:
#	@${REINPLACE_CMD} -e 's|--libs "libxfce4panel-1.0"|& "libxfcegui4-1.0"|g; \
#		s|--cflags "libxfce4panel-1.0"|& "libxfcegui4-1.0"|g; \
#		s|exo-0.3|exo-1|g' \
#		${WRKSRC}/configure

.include <bsd.port.mk>
