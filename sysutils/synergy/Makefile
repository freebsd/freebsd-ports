# $FreeBSD$

PORTNAME=	synergy
DISTVERSION=	1.13.1.41
DISTVERSIONSUFFIX=	-stable
PORTEPOCH=	1
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Mouse and keyboard sharing utility

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake compiler:c++14-lang cpe localbase:ldflags qt:5 ssl xorg
CPE_VENDOR=	synergy-foss
USE_XORG=	ice xtst x11 sm xext xinerama xrandr xi
USE_QT=		core network widgets buildtools_build linguisttools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	symless
GH_PROJECT=	synergy-core
GH_TUPLE=	google:googletest:18f8200e3079b0e54fa00cb7ac55d4c39dcf6da6:google_googletest/ext/googletest

CONFLICTS=	synergy-1

CMAKE_ARGS=	-DSYNERGY_REVISION:STRING=${PORTVERSION:S/.//g}00 # it expects a 8-digit hash

PORTEXAMPLES=	synergy.conf.example synergy.conf.example-basic \
		synergy.conf.example-advanced

OPTIONS_DEFINE=			AVAHI_LIBDNS EXAMPLES
OPTIONS_DEFAULT=		AVAHI_LIBDNS

AVAHI_LIBDNS_DESC=		Use libdns from avahi to avoid conflicts with KDE/Gnome
AVAHI_LIBDNS_USES=		pkgconfig
AVAHI_LIBDNS_CFLAGS=		`pkg-config --cflags avahi-compat-libdns_sd`
AVAHI_LIBDNS_LDFLAGS=		`pkg-config --libs avahi-compat-libdns_sd`
AVAHI_LIBDNS_LIB_DEPENDS=	libdns_sd.so:net/avahi-libdns
AVAHI_LIBDNS_LDFLAGS_OFF=	-ldns_sd
AVAHI_LIBDNS_LIB_DEPENDS_OFF=	libdns_sd.so:net/mDNSResponder

post-patch:
	@${REINPLACE_CMD} -e 's|return "/etc"|return "${PREFIX}/etc"|' \
		${WRKSRC}/src/lib/arch/unix/ArchFileUnix.cpp
	@${REINPLACE_CMD} -e 's|/etc/synergy.conf|${PREFIX}/etc/synergy.conf|' \
		${WRKSRC}/doc/synergys.man

do-install: # https://github.com/symless/synergy-core/issues/6895
.for f in synergyc synergys
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${f}.man \
		${STAGEDIR}${MANPREFIX}/man/man1/${f}.1
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/synergy.conf.example-basic ${STAGEDIR}${PREFIX}/etc/synergy.conf.sample # server config

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
