PORTNAME=	synergy
DISTVERSION=	1.15.1
DISTVERSIONSUFFIX=	+r1
PORTEPOCH=	3
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Mouse and keyboard sharing utility
WWW=		https://symless.com/synergy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libnotify.so:devel/libnotify \
		libxkbfile.so:x11/libxkbfile

USES=		cmake compiler:c++14-lang cpe gnome localbase:ldflags pkgconfig qt:6 ssl xorg
CPE_VENDOR=	synergy-foss
USE_QT=		base tools:build
USE_GNOME=	gdkpixbuf2 glib20
USE_XORG=	ice xtst x11 sm xext xinerama xrandr xi

USE_GITHUB=	yes
GH_ACCOUNT=	symless
GH_TUPLE=	google:googletest:18f8200e3079b0e54fa00cb7ac55d4c39dcf6da6:google_googletest/ext/googletest \
		mohabouje:WinToast:8abb85b:WinToast/ext/WinToast \
		zeux:pugixml:9e382f9:pugixml/ext/pugixml

CMAKE_ARGS=	-DSYNERGY_REVISION:STRING=${PORTVERSION:S/.//g}00 # it expects a 8-digit hash
CMAKE_OFF=	BUILD_TESTS

PORTEXAMPLES=	synergy.conf.example synergy.conf.example-basic \
		synergy.conf.example-advanced

OPTIONS_DEFINE=			AVAHI_LIBDNS EXAMPLES LEGACY
OPTIONS_DEFAULT=		AVAHI_LIBDNS
OPTIONS_SUB=			yes

AVAHI_LIBDNS_DESC=		Use libdns from avahi to avoid conflicts with KDE/Gnome
AVAHI_LIBDNS_CFLAGS=		`pkg-config --cflags avahi-compat-libdns_sd`
AVAHI_LIBDNS_LDFLAGS=		`pkg-config --libs avahi-compat-libdns_sd`
AVAHI_LIBDNS_LIB_DEPENDS=	libdns_sd.so:net/avahi-libdns
AVAHI_LIBDNS_LDFLAGS_OFF=	-ldns_sd
AVAHI_LIBDNS_LIB_DEPENDS_OFF=	libdns_sd.so:net/mDNSResponder

LEGACY_DESC=			Build the legacy GUI, synergyd, installer
LEGACY_CONFIGURE_ENV_OFF=	SYNERGY_NO_LEGACY=true
LEGACY_USE=			QT=gui

post-patch:
	# Hardcoded path needs to be replaced with
	#   --with-xkb-base defined in x11/keyboard-config
	@${REINPLACE_CMD} -e 's|/usr/share/X11/xkb|${PREFIX}/share/X11/xkb|' \
		${WRKSRC}/src/lib/synergy/unix/AppUtilUnix.cpp
	@${REINPLACE_CMD} -e 's|return "/etc"|return "${PREFIX}/etc"|' \
		${WRKSRC}/src/lib/arch/unix/ArchFileUnix.cpp

do-install: # https://github.com/symless/synergy-core/issues/6895
.for f in synergyc synergys
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/syntool ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/synergy.conf.example-basic ${STAGEDIR}${PREFIX}/etc/synergy.conf.sample # server config

do-install-LEGACY-on:
.for f in synergy synergyd
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${BUILD_WRKSRC}/bin/unittests \
		${BUILD_WRKSRC}/bin/integtests

.include <bsd.port.mk>
