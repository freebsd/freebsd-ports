# New ports collection makefile for:	gnome-subtitles
# Date created:				23 March 2007
# Whom:				Marcin Simonides <marcin@studio4plus.com>
#
# $FreeBSD$
#

PORTNAME=	gnome-subtitles
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Subtitle editor with video preview

LIB_DEPENDS=	enchant.1:${PORTSDIR}/textproc/enchant
BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		${LOCALBASE}/lib/sublib/sublib.dll:${PORTSDIR}/multimedia/sublib
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono \
		${LOCALBASE}/lib/sublib/sublib.dll:${PORTSDIR}/multimedia/sublib

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gtksharp20 gnomesharp20 gnomedocutils
USE_GSTREAMER=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
GCONF_SCHEMAS=	gnome-subtitles.schemas
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes

USE_LDCONFIG=	${PREFIX}/lib/gnome-subtitles

MAN1=		gnome-subtitles.1

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
