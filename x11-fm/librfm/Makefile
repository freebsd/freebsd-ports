# Created by: Rodrigo Osorio <rodrigo@freebsd.org>
# $FreeBSD$

PORTNAME=	librfm
PORTVERSION=	5.3.14.6
CATEGORIES=	x11-fm
MASTER_SITES=	SF/xffm/${PORTVERSION}
DISTNAME=	${PORTNAME}5-${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Basic library used by some rfm applications

LICENSE=	GPLv3

BUILD_DEPENDS=	gawk:${PORTSDIR}/japanese/gawk
LIB_DEPENDS=	libtubo.so:${PORTSDIR}/x11-fm/libtubo \
		libdbh.so:${PORTSDIR}/databases/dbh \
		libzip.so:${PORTSDIR}/archivers/libzip \
		librsvg-2.so:${PORTSDIR}/graphics/librsvg2

OPTIONS_DEFINE=	NLS

CONFIGURE_ARGS+=--with-pkglibdata
MAKE_JOB_UNSAFE=yes
INSTALLS_ICONS=	yes
USES=		gmake libtool:keepla pkgconfig tar:bzip2 gettext
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
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
