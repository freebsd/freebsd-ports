# New ports collection makefile for:	banshee
# Date created:				Jul 10 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	banshee
PORTVERSION=	1.5.0
CATEGORIES=	multimedia audio
MASTER_SITES=	http://download.banshee-project.org/banshee/ \
		http://download.banshee-project.org/banshee/unstable/${PORTVERSION}/
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
		${LOCALBASE}/libdata/pkgconfig/mono-addins.pc:${PORTSDIR}/devel/mono-addins

OPTIONS=	DOCS "Install documentation" on \
		MTP "Enable MTP support" on \
		BPMDETECT "Enable BPM detection" on
#		IPOD "Enable iPod support" on \

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gtksharp20 gnomesharp20
USE_GSTREAMER=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}-1
USE_XORG=	xrandr xxf86vm
USE_SQLITE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--disable-boo --disable-shave

# Need absolute path for build/icon-install-theme.
INSTALL=	/usr/bin/install

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"

.if !defined(WITHOUT_DOCS) && !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/bin/monodocer:${PORTSDIR}/devel/monodoc
.else
CONFIGURE_ARGS+=	--disable-docs
.endif

#.if !defined(WITHOUT_IPOD)
#LIB_PC_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/ipod-sharp-ui.pc:${PORTSDIR}/audio/ipod-sharp
#PLIST_SUB+=	OPT_IPOD=""
#.else
CONFIGURE_ARGS+=	--disable-ipod
PLIST_SUB+=	OPT_IPOD="@comment "
#.endif

.if !defined(WITHOUT_MTP)
LIB_DEPENDS+=	mtp.8:${PORTSDIR}/audio/libmtp
PLIST_SUB+=	OPT_MTP=""
.else
CONFIGURE_ARGS+=	--disable-mtp
PLIST_SUB+=	OPT_MTP="@comment "
.endif

.if !defined(WITHOUT_BPMDETECT)
USE_GSTREAMER+=	soundtouch
.endif

post-patch:
	@${REINPLACE_CMD} "s|!/bin/bash|!${PREFIX}/bin/bash|" \
				${WRKSRC}/build/icon-theme-installer \
				${WRKSRC}/build/private-icon-theme-installer \
				${WRKSRC}/data/desktop-files/update-desktop-file.sh \
				${WRKSRC}/src/Clients/Booter/banshee-1.in
	@${REINPLACE_CMD} 's|sed -r|sed -E|' \
				${WRKSRC}/data/icon-theme-hicolor/Makefile.in
#				${WRKSRC}/configure \

# XXX - This is gross.
post-configure:
	@${REINPLACE_CMD} -e 's|^\(MSGFMT =\).*|\1 ${LOCALBASE}/bin/msgfmt|' \
		-e 's|^\(GMSGFMT =\).*|\1 ${LOCALBASE}/bin/msgfmt|' \
			${WRKSRC}/po/Makefile

# XXX - Really ugly too.
pre-build:
	${MKDIR} ${WRKSRC}/bin/share/banshee-1/icons/hicolor/scalable/

# XXX - This one is the best.
pre-install:
.for i in 16x16 22x22 32x32 48x48 128x128 scalable
. for j in actions categories devices status
	@${MKDIR} ${PREFIX}/share/banshee-1/icons/hicolor/$i/$j/
. endfor
.endfor

.include <bsd.port.post.mk>
