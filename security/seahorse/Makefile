# New ports collection makefile for:	Seahorse
# Date created:		08 March 2000
# Whom:			Dave McKay <dave@mu.org>
#
# $FreeBSD$
#   $MCom: ports/security/seahorse/Makefile,v 1.8 2005/10/14 20:39:58 adamw Exp $
#

PORTNAME=	seahorse
PORTVERSION=	0.8
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=sources/${PORTNAME}/0.8
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A front end for GnuPG

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	gpgme.15:${PORTSDIR}/security/gpgme

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix libgnomeui
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
INSTALLS_OMF=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--disable-gpg-check
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	seahorse.schemas

OPTIONS=	GEDIT "Enable the gedit plug-in" on \
		NAUTILUS "Enable the Nautilus component" on \
		LDAP "Enable LDAP support" on \
		HKP "Enable HKP keyserver interface" on

.include <bsd.port.pre.mk>

.if defined(WITH_GEDIT)
BUILD_DEPENDS+=	gedit:${PORTSDIR}/editors/gedit
RUN_DEPENDS+=	gedit:${PORTSDIR}/editors/gedit
PLIST_SUB+=	GEDIT=""
GCONF_SCHEMAS+=	seahorse-gedit.schemas
.else
PLIST_SUB+=	GEDIT="@comment "
CONFIGURE_ARGS+=--disable-gedit
.endif

.if defined(WITH_NAUTILUS)
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

post-patch:
	@${REINPLACE_CMD} -e 's|gedit-2.10|gedit-2.12|g' \
		${WRKSRC}/configure

post-install:
	-@update-desktop-database

.include <bsd.port.post.mk>
