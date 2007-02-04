# New ports collection makefile for:	blam
# Date created:				20040812
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.22 2006/10/26 05:32:53 tmclau02 Exp $
#

PORTNAME=	blam
PORTVERSION=	1.8.2
PORTREVISION=	6
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.8

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Mono based RSS feed reader

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gecko-sharp.pc:${PORTSDIR}/www/gecko-sharp10
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gecko-sharp.pc:${PORTSDIR}/www/gecko-sharp10

USE_GECKO=	firefox mozilla
USE_GNOME=	gnomeprefix gnomehack intlhack intltool libgnomeui gtksharp10
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mozilla=${GECKO}
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	blam.schemas

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
.if ${GECKO}!="mozilla"
EXTRA_PATCHES+= ${PATCHDIR}/extra-libblam_blam-gecko-utils.cpp
.endif
.include <bsd.port.post.mk>
