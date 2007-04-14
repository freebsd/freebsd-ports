# New ports collection makefile for:	gnome-subtitles
# Date created:				23 March 2007
# Whom:				Marcin Simonides <marcin@studio4plus.com>
#
# $FreeBSD$
#

PORTNAME=       gnome-subtitles
PORTVERSION=    0.3
CATEGORIES=     multimedia
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= ${PORTNAME}

MAINTAINER=     marcin@studio4plus.com
COMMENT=        Subtitle editor with video preview

BUILD_DEPENDS=  mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=    mono:${PORTSDIR}/lang/mono

USE_GNOME=      gnomeprefix gtksharp20 gnomesharp20
GNU_CONFIGURE=	yes
GCONF_SCHEMAS=	gnome-subtitles.schemas

.if !defined(WITHOUT_MPLAYER)
    RUN_DEPENDS+=   mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
