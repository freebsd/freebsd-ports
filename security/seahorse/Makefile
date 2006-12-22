# New ports collection makefile for:	Seahorse
# Date created:		08 March 2000
# Whom:			Dave McKay <dave@mu.org>
#
# $FreeBSD$
#   $MCom: ports/security/seahorse/Makefile,v 1.18 2006/10/01 01:56:57 ahze Exp $
#

PORTNAME=	seahorse
PORTVERSION=	0.8.2
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=sources/${PORTNAME}/0.8
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A front end for GnuPG

BUILD_DEPENDS=	gpgv:${PORTSDIR}/security/gnupg1
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	gpgme.17:${PORTSDIR}/security/gpgme

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
CONFIGURE_ARGS=	--disable-gpg-check
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	seahorse.schemas

OPTIONS=	NAUTILUS "Enable the Nautilus component" on \
		LDAP "Enable LDAP support" on \
		HKP "Enable HKP keyserver interface" on
#		GEDIT "Enable GEdit plug-in support" on

.include <bsd.port.pre.mk>

# Gedit not working right now..
WITHOUT_GEDIT=	yes
.if !defined(WITHOUT_GEDIT)
BUILD_DEPENDS+=	gedit:${PORTSDIR}/editors/gedit
RUN_DEPENDS+=	gedit:${PORTSDIR}/editors/gedit
PLIST_SUB+=	GEDIT=""
GCONF_SCHEMAS+=	seahorse-gedit.schemas
.else
PLIST_SUB+=	GEDIT="@comment "
CONFIGURE_ARGS+=--disable-gedit
.endif

.if !defined(WITHOUT_NAUTILUS)
USE_GNOME+=	nautilus2
PLIST_SUB+=	NAUTILUS=""
.else
PLIST_SUB+=	NAUTILUS="@comment "
CONFIGURE_ARGS+=--disable-nautilus
.endif

.if !defined(WITHOUT_LDAP)
USE_OPENLDAP=	yes
.else
CONFIGURE_ARGS+=--disable-ldap
.endif

.if !defined(WITHOUT_HKP)
LIB_DEPENDS+=	soup-2.2.8:${PORTSDIR}/devel/libsoup
.else
CONFIGURE_ARGS+=--disable-hkp
.endif

post-install:
	-@update-desktop-database

.include <bsd.port.post.mk>
