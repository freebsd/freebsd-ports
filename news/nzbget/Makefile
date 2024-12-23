PORTNAME=	nzbget
DISTVERSIONPREFIX=	v
DISTVERSION=	24.4
PORTREVISION=	0
CATEGORIES=	news

MAINTAINER=	a13xlevy@pm.me
COMMENT=	Binary newsreader supporting NZB files
WWW=		https://nzbget.net/

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_json.so:devel/boost-libs
RUN_DEPENDS=	7-zip>0:archivers/7-zip \
		unrar>0:archivers/unrar

# Since v24.4 nzbget maintainers switched from libpar2 to a fork of par2cmdline-turbo which is in its own repository.
# See https://github.com/nzbgetcom/nzbget/blob/v24.4/cmake/par2-turbo.cmake for the version to pull
PAR2CMDLINE_TURBO_VERSION=1.1.1-nzbget

USES=		cmake:testing gnome ssl
USE_GNOME=	libxml2
USE_GITHUB=	yes
GH_ACCOUNT=	nzbgetcom
GH_PROJECT=	nzbget par2cmdline-turbo:par2
GH_TAGNAME= ${DISTVERSIONPREFIX}${PAR2CMDLINE_TURBO_VERSION}:par2
USE_RC_SUBR=	nzbget

BINMODE=	0755

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		DOCS NCURSES PAR2 PYTHON
OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	NCURSES PAR2

PAR2_DESC=		PAR 2.0 compatible file verification and repair

NCURSES_USES=	ncurses

NCURSES_CMAKE_BOOL_OFF=	DISABLE_CURSES
PAR2_CMAKE_BOOL_OFF=	DISABLE_PARCHECK
CMAKE_TESTING_ON=	ENABLE_TESTS

PYTHON_USES=	python:run,3.8+

.include <bsd.port.options.mk>

.if (${ARCH} == "i386")
CMAKE_ARGS+=	-DDISABLE_SIGCHLD_HANDLER=ON
.endif

# We need to manually extract par2cmdline-turbo source repository as the cmake option FETCHCONTENT_FULLY_DISCONNECTED is ON by default for ports
post-extract-PAR2-on:
	${MKDIR} ${BUILD_WRKSRC}/_deps
	${MV} ${WRKDIR}/par2cmdline-turbo-${PAR2CMDLINE_TURBO_VERSION} ${BUILD_WRKSRC}/_deps/par2-turbo-src

# Clean up par2 static libraries and delete empty directories
post-stage-PAR2-on:
	${RM} ${STAGEDIR}${BUILD_WRKSRC}/lib/*.a
	${FIND} ${STAGEDIR} -depth -type d -not -path "${STAGEDIR}${PREFIX}*" -empty -delete

post-install:
	${INSTALL_DATA} ${WRKSRC}/nzbget.conf \
		${STAGEDIR}${PREFIX}/etc/nzbget.conf.sample

.include <bsd.port.mk>
