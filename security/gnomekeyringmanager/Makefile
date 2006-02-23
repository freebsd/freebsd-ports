# New ports collection makefile for:	gnomekeyringmanager
# Date created:				2004 12 July
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/security/gnomekeyringmanager/Makefile,v 1.14 2005/09/07 14:54:53 adamw Exp $
#

PORTNAME=	gnomekeyringmanager
PORTVERSION=	2.12.0
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-keyring-manager/2.12
DISTNAME=	gnome-keyring-manager-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME keyring manager

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/gnome-doc-utils.pc:${PORTSDIR}/textproc/gnomedocutils
LIB_DEPENDS=	gnome-keyring:${PORTSDIR}/security/gnomekeyring

USE_X_PREFIX=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui
CONFIGURE_ARGS=	--with-help-dir=${PREFIX}/share/gnome/help
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnome-keyring-manager.1
GCONF_SCHEMAS=	gnome-keyring-manager.schemas

.include <bsd.port.mk>
