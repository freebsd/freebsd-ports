# Created by: Rodrigo Osorio <rodrigo@freebsd.org>
# $FreeBSD$

PORTNAME=	librfm
PORTVERSION=	5.3.16.4
CATEGORIES=	x11-fm
MASTER_SITES=	SF/xffm/5.3.16.3
DISTNAME=	${PORTNAME}5-${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Basic library used by some rfm applications

LICENSE=	GPLv3

BUILD_DEPENDS=	gawk:lang/gawk
LIB_DEPENDS=	libtubo.so:x11-fm/libtubo \
		libdbh.so:databases/dbh \
		libzip.so:archivers/libzip \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

OPTIONS_DEFINE=	NLS

CONFIGURE_ARGS+=--with-pkglibdata
INSTALLS_ICONS=	yes
USES=		autoreconf gettext gnome gmake libtool:keepla pkgconfig \
		tar:bzip2 xorg
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool cairo libxml2 librsvg2
USE_XORG+=	x11
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

WRKSRC=	${WRKDIR}/${PORTNAME}5-${PORTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=--disable-nls
.endif

.include <bsd.port.mk>
