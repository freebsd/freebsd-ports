# New ports collection makefile for:	Seahorse
# Date created:		08 March 2000
# Whom:			Dave McKay <dave@mu.org>
#
# $FreeBSD$
#

PORTNAME=	seahorse
PORTVERSION=	0.7.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=sources/${PORTNAME}/0.7
DIST_SUBDIR=	gnome2

MAINTAINER=	asa@gascom.ru
COMMENT=	A front end for GnuPG

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	gpgme.14:${PORTSDIR}/security/gpgme

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix eel2
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
INSTALLS_OMF=	yes
CONFIGURE_ARGS=	--disable-gpg-check
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	seahorse.schemas

OPTIONS=	GEDIT "Enable the gedit plug-in" on

.include <bsd.port.pre.mk>

.if defined(WITH_GEDIT)
BUILD_DEPENDS+=	gedit:${PORTSDIR}/editors/gedit2
RUN_DEPENDS+=	gedit:${PORTSDIR}/editors/gedit2
PLIST_SUB+=	GEDIT=""
.else
PLIST_SUB+=	GEDIT="@comment "
CONFIGURE_ARGS+=--disable-gedit
.endif

.include <bsd.port.post.mk>
