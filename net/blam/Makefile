# New ports collection makefile for:	blam
# Date created:				20040812
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.19 2005/11/06 07:17:04 tmclau02 Exp $
#

PORTNAME=	blam
PORTVERSION=	1.8.2
PORTREVISION=	4
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.8

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Mono based RSS feed reader

BUILD_DEPENDS=	gapi-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp10 \
		${X11BASE}/libdata/pkgconfig/gecko-sharp.pc:${PORTSDIR}/www/gecko-sharp10
RUN_DEPENDS=	gapi-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp10 \
		${X11BASE}/libdata/pkgconfig/gecko-sharp.pc:${PORTSDIR}/www/gecko-sharp10

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
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
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

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
