# Created by: Marcin Simonides <marcin@studio4plus.com>
# $FreeBSD$

PORTNAME=	gnome-subtitles
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	armin@frozen-zone.org
COMMENT=	Subtitle editor with video preview

LICENSE=	GPLv2

LIB_DEPENDS=	enchant.1:${PORTSDIR}/textproc/enchant \
		gtkspell.0:${PORTSDIR}/textproc/gtkspell
BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

USES=		gmake pkgconfig
USE_GNOME=	gnomeprefix gtksharp20 gnomesharp20 gnomedocutils
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GCONF_SCHEMAS=	gnome-subtitles.schemas
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes

USE_LDCONFIG=	${PREFIX}/lib/gnome-subtitles

MAN1=		gnome-subtitles.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
