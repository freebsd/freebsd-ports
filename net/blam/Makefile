# New ports collection makefile for:	blam
# Date created:				20040812
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $Id: Makefile,v 1.10 2005/05/10 16:59:13 mezz7 Exp $
# $FreeBSD$
#

PORTNAME=	blam
PORTVERSION=	1.8.0
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.8

MAINTAINER=	tmclaugh@sdf.lonestar.org
COMMENT=	Mono based RSS feed reader

BUILD_DEPENDS=	gapi-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp \
		${X11BASE}/libdata/pkgconfig/gecko-sharp.pc:${PORTSDIR}/www/gecko-sharp
RUN_DEPENDS=	${BUILD_DEPENDS}

.if !defined(WITH_MOZILLA)
MOZILLA=	mozilla
.else
.if ${WITH_MOZILLA}=="firefox"
MOZILLA=	firefox
.else
MOZILLA=	mozilla
.endif
.endif

USE_GNOME=	gnomeprefix gnomehack intlhack intltool libgnomeui
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=   yes
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--with-mozilla=${MOZILLA}
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	blam.schemas

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " By default ${PORTNAME} uses www/mozilla for html rendering, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  firefox       "
	@${ECHO_MSG} ""

.include <bsd.port.mk>
