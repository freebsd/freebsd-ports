# New ports collection makefile for:	gnomekeyringmanager
# Date created:				2004 12 July
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/security/gnome-keyring-manager/Makefile,v 1.27 2007/03/13 12:35:40 ahze Exp $
#

PORTNAME=	gnome-keyring-manager
PORTVERSION=	2.18.0
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME keyring manager

LIB_DEPENDS=	gnome-keyring:${PORTSDIR}/security/gnome-keyring

USE_XLIB=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui gnomedocutils
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnome-keyring-manager.1
GCONF_SCHEMAS=	gnome-keyring-manager.schemas

.include <bsd.port.mk>
