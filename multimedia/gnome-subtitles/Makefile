# Created by: Marcin Simonides <marcin@studio4plus.com>
# $FreeBSD$

PORTNAME=	gnome-subtitles
PORTVERSION=	1.3
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Subtitle editor with video preview

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libenchant.so:textproc/enchant \
		libgtkspell.so:textproc/gtkspell

USES=		cpe gmake mono pkgconfig libtool localbase desktop-file-utils
CPE_VENDOR=	pedro_castro
USE_GNOME=	gnomeprefix gtksharp20 gnomesharp20 gnomedocutils intltool
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
GCONF_SCHEMAS=	gnome-subtitles.schemas
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_UNSAFE=yes

USE_LDCONFIG=	${PREFIX}/lib/gnome-subtitles

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	NLS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gnome-subtitles/libgstreamer_playbin.so

.include <bsd.port.mk>
