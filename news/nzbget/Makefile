PORTNAME=	nzbget
DISTVERSIONPREFIX=	v
DISTVERSION=	25.2
CATEGORIES=	news

MAINTAINER=	a13xlevy@pm.me
COMMENT=	Binary newsreader supporting NZB files
WWW=		https://nzbget.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_json.so:devel/boost-libs
RUN_DEPENDS=	7-zip>0:archivers/7-zip \
		unrar>0:archivers/unrar

# Since v24.4 nzbget maintainers switched from libpar2 to a fork of par2cmdline-turbo which is in its own repository.
# See https://github.com/nzbgetcom/nzbget/blob/v24.4/cmake/par2-turbo.cmake for the version to pull
PAR2CMDLINE_TURBO_VERSION=	1.3.0

USES=		cmake:testing,noninja gnome ssl
USE_GITHUB=	yes
GH_ACCOUNT=	nzbgetcom
GH_PROJECT=	nzbget par2cmdline-turbo:par2
GH_TAGNAME=	${DISTVERSIONPREFIX}${PAR2CMDLINE_TURBO_VERSION}:par2
USE_GNOME=	libxml2
USE_RC_SUBR=	nzbget
CMAKE_TESTING_ON=	ENABLE_TESTS

BINMODE=	0755

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		DOCS NCURSES PAR2 PYTHON
OPTIONS_DEFAULT=	NCURSES PAR2

PAR2_DESC=	PAR 2.0 compatible file verification and repair

NCURSES_USES=	ncurses

NCURSES_CMAKE_BOOL_OFF=	DISABLE_CURSES
PAR2_CMAKE_BOOL_OFF=	DISABLE_PARCHECK

PYTHON_USES=	python:run,3.9+

.include <bsd.port.options.mk>

.if (${ARCH} == "i386")
CMAKE_ARGS+=	-DDISABLE_SIGCHLD_HANDLER=ON
.endif

pre-configure-PAR2-on:
	${MKDIR} ${BUILD_WRKSRC}/par2-turbo/src
	${MV} ${WRKDIR}/par2cmdline-turbo-${PAR2CMDLINE_TURBO_VERSION} ${BUILD_WRKSRC}/par2-turbo/src/par2-turbo

post-install:
	${INSTALL_DATA} ${WRKSRC}/nzbget.conf \
		${STAGEDIR}${PREFIX}/etc/nzbget.conf.sample

.include <bsd.port.mk>
