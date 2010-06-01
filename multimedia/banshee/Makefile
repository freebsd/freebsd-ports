# New ports collection makefile for:	banshee
# Date created:				Jul 10 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	banshee
PORTVERSION=	1.6.0
PORTEPOCH=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	http://download.banshee-project.org/${PORTNAME}/stable/${PORTVERSION}/
DISTNAME=	${PORTNAME}-1-${PORTVERSION}

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Music management and playback for gnome

# Could do without bash, but it's brought in by gnome anyway.
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/mono.pc:${PORTSDIR}/lang/mono \
		${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-1.0.pc:${PORTSDIR}/devel/ndesk-dbus \
		${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-glib-1.0.pc:${PORTSDIR}/devel/ndesk-dbus-glib \
		${LOCALBASE}/libdata/pkgconfig/taglib-sharp.pc:${PORTSDIR}/audio/taglib-sharp \
		${LOCALBASE}/libdata/pkgconfig/mono-zeroconf.pc:${PORTSDIR}/net/mono-zeroconf \
		${LOCALBASE}/libdata/pkgconfig/mono-addins.pc:${PORTSDIR}/devel/mono-addins \
		${LOCALBASE}/libdata/pkgconfig/notify-sharp.pc:${PORTSDIR}/devel/notify-sharp

OPTIONS=	DOCS      "Install documentation"    on \
		BOO       "Enable Boo support"       off \
		BPMDETECT "Enable BPM detection"     on \
		MTP       "Enable MTP support"       on \
		IPOD      "Enable iPod support"      on \
		WEBKIT    "Enable Wikipedia support" on \
		YOUTUBE   "Enable Youtube support"   on

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gtksharp20 gnomesharp20
USE_GSTREAMER=	cdparanoia
USE_GETTEXT=	yes
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}-1
USE_XORG=	xrandr xxf86vm
USE_SQLITE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-vendor-build-id=FreeBSD\ BSD\#\ Project \
			--disable-gapless-playback

# Need absolute path for build/icon-install-theme.
INSTALL=	/usr/bin/install

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"

.if defined(WITHOUT_DOCS) || defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--disable-docs
.endif

.if !defined(WITHOUT_BPMDETECT)
USE_GSTREAMER+=	soundtouch
.endif

.if defined(WITH_BOO)
CONFIGURE_ARGS+=--enable-boo
BUILD_DEPENDS+=	booc:${PORTSDIR}/lang/boo
RUN_DEPENDS+=	booc:${PORTSDIR}/lang/boo
PLIST_SUB+=	OPT_BOO=""
.else
CONFIGURE_ARGS+=--disable-boo
PLIST_SUB+=	OPT_BOO="@comment "
.endif

.if !defined(WITHOUT_IPOD)
CONFIGURE_ARGS+=--enable-ipod
LIB_PC_DEPENDS+=${LOCALBASE}/libdata/pkgconfig/ipod-sharp-ui.pc:${PORTSDIR}/audio/ipod-sharp
PLIST_SUB+=	OPT_IPOD=""
.else
CONFIGURE_ARGS+=--disable-ipod
PLIST_SUB+=	OPT_IPOD="@comment "
.endif

.if !defined(WITHOUT_MTP)
CONFIGURE_ARGS+=--enable-mtp
LIB_DEPENDS+=	mtp.11:${PORTSDIR}/audio/libmtp
PLIST_SUB+=	OPT_MTP=""
.else
CONFIGURE_ARGS+=--disable-mtp
PLIST_SUB+=	OPT_MTP="@comment "
.endif

.if !defined(WITHOUT_WEBKIT)
CONFIGURE_ARGS+=--enable-webkit
LIB_PC_DEPENDS+=${LOCALBASE}/libdata/pkgconfig/webkit-sharp-1.0.pc:${PORTSDIR}/www/webkit-sharp
PLIST_SUB+=	OPT_WEBKIT=""
.else
CONFIGURE_ARGS+=--disable-webkit
PLIST_SUB+=	OPT_WEBKIT="@comment "
.endif

.if !defined(WITHOUT_YOUTUBE)
CONFIGURE_ARGS+=--enable-youtube
LIB_PC_DEPENDS+=${LOCALBASE}/libdata/pkgconfig/gdata-sharp-youtube.pc:${PORTSDIR}/devel/google-gdata
PLIST_SUB+=	OPT_YOUTUBE=""
.else
CONFIGURE_ARGS+=--disable-youtube
PLIST_SUB+=	OPT_YOUTUBE="@comment "
.endif

.include <bsd.port.post.mk>
