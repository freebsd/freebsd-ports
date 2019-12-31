# $FreeBSD$

PORTNAME=	synergy-1
DISTVERSION=	1.11.0
DISTVERSIONSUFFIX=	-stable
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Mouse and keyboard sharing utility

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake compiler:c++14-lang cpe ssl xorg
CPE_VENDOR=	synergy-foss
USE_GITHUB=	yes
GH_ACCOUNT=	symless
GH_PROJECT=	synergy-core
USE_XORG=	ice xtst x11 sm xext xinerama xrandr xi

CONFLICTS=	synergy

CMAKE_OFF=	SYNERGY_BUILD_LEGACY_INSTALLER SYNERGY_BUILD_LEGACY_GUI
CMAKE_ARGS=	-DSYNERGY_REVISION:STRING=${DISTVERSION:S/.//g}0000 # it expects a 7-digit hash

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

MAKE_JOBS_UNSAFE=yes

PORTEXAMPLES=	synergy.conf.example synergy.conf.example-basic \
		synergy.conf.example-advanced

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|return "/etc"|return "${PREFIX}/etc"|' \
		${WRKSRC}/src/lib/arch/unix/ArchFileUnix.cpp
	@${REINPLACE_CMD} -e 's|/etc/synergy.conf|${PREFIX}/etc/synergy.conf|' \
		${WRKSRC}/doc/synergys.man

do-install:
.for f in synergyc synergyd synergys
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
.for f in synergyc synergys
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
