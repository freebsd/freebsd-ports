# New ports collection makefile for:	nautilus-cd-burner
# Date created:				13 April 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nautilus-cd-burner
PORTVERSION=	2.10.2
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.10
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD burner view for Nautilus

RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools-cjk

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack intlhack nautilus2
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	ncb.schemas

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/growisofs)
WITH_DVD=	yes
.endif

.if defined(WITH_DVD)
RUN_DEPENDS+=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "${PORTNAME} has the following configurable option(s):"
	@${ECHO_MSG} "	WITH_DVD	Enable DVD burning support"
	@${ECHO_MSG} ""

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
