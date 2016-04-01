# Created by: Rodrigo Osorio <rodrigo@freebsd.org>
# $FreeBSD$

PORTNAME=	librfm
PORTVERSION=	5.3.16.3
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	SF/xffm/${PORTVERSION}
DISTNAME=	${PORTNAME}5-${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Basic library used by some rfm applications

LICENSE=	GPLv3

BUILD_DEPENDS=	gawk:lang/gawk
LIB_DEPENDS=	libtubo.so:x11-fm/libtubo \
		libdbh.so:databases/dbh \
		libzip.so:archivers/libzip \
		librsvg-2.so:graphics/librsvg2

OPTIONS_DEFINE=	NLS

CONFIGURE_ARGS+=--with-pkglibdata
MAKE_JOB_UNSAFE=yes
INSTALLS_ICONS=	yes
USES=		gettext gmake libtool:keepla pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool
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
