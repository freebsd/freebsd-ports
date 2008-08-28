# New ports collection makefile for:	banshee
# Date created:				Jul 10 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	banshee
PORTVERSION=	1.2.1
CATEGORIES=	multimedia audio
MASTER_SITES=	http://download.banshee-project.org/banshee/
DISTNAME=	${PORTNAME}-1-${PORTVERSION}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Music management and playback for gnome

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/mono.pc:${PORTSDIR}/lang/mono \
		${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-1.0.pc:${PORTSDIR}/devel/ndesk-dbus \
		${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-glib-1.0.pc:${PORTSDIR}/devel/ndesk-dbus-glib \
		${LOCALBASE}/libdata/pkgconfig/taglib-sharp.pc:${PORTSDIR}/audio/taglib-sharp \
		${LOCALBASE}/libdata/pkgconfig/mono-zeroconf.pc:${PORTSDIR}/net/mono-zeroconf \
		${LOCALBASE}/libdata/pkgconfig/mono-addins.pc:${PORTSDIR}/devel/mono-addins \
		${LOCALBASE}/libdata/pkgconfig/sqlite3.pc:${PORTSDIR}/databases/sqlite3

OPTIONS=	DOCS "Install documentation" on

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gtksharp20 gnomesharp20
USE_GSTREAMER=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}-1
USE_XORG=	xrandr xxf86vm
INSTALLS_ICONS=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--disable-boo --disable-ipod --disable-mtp

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"

.if !defined(WITHOUT_DOCS) && !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/bin/monodocer:${PORTSDIR}/devel/monodoc
.else
CONFIGURE_ARGS+=	--disable-docs
.endif

post-patch:
	@${REINPLACE_CMD} 's|#!/bin/bash|#!/bin/sh|' \
				${WRKSRC}/src/Clients/banshee-1.in \
				${WRKSRC}/build/icon-theme-installer \
				${WRKSRC}/build/private-icon-theme-installer
	@${REINPLACE_CMD} 's|\[\[|\[|g;s|\]\]|\]|g;s|==|=|g;s/||/-o/g' \
				${WRKSRC}/build/private-icon-theme-installer
	@${REINPLACE_CMD} 's|-a banshee-1||' \
				${WRKSRC}/src/Clients/banshee-1.in
#	@${REINPLACE_CMD} 's|sed -r|sed|' \
#				${WRKSRC}/configure \
#				${WRKSRC}/data/icon-theme-hicolor/Makefile.in

# XXX - This is gross.
post-configure:
	@${REINPLACE_CMD} -e 's|^\(MSGFMT =\)|\1 ${LOCALBASE}/bin/msgfmt|' \
			 -e 's|^\(GMSGFMT =\)|\1 ${LOCALBASE}/bin/msgfmt|' \
				${WRKSRC}/po/Makefile

pre-build:
.for i in 16x16 22x22 48x48 scalable
	${MKDIR} ${WRKSRC}/bin/share/banshee-1/icons/hicolor/$i/categories
.endfor

pre-install:
.for i in 16x16 22x22 48x48 scalable
	${MKDIR} ${PREFIX}/share/banshee-1/icons/hicolor/$i/categories
.endfor

.include <bsd.port.post.mk>
