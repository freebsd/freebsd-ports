PORTNAME=	nzbget
DISTVERSIONPREFIX=	v
DISTVERSION=	24.3
CATEGORIES=	news

MAINTAINER=	a13xlevy@pm.me
COMMENT=	Binary newsreader supporting NZB files
WWW=		https://nzbget.net/

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_json.so:devel/boost-libs \
		libxml2.so:textproc/libxml2
RUN_DEPENDS=	7-zip>0:archivers/7-zip \
		unrar>0:archivers/unrar

USES=		cmake:testing python:build ssl
USE_GITHUB=	yes
GH_ACCOUNT=	nzbgetcom
GH_PROJECT=	nzbget
USE_RC_SUBR=	nzbget

BINMODE=	0755

SUB_FILES=	pkg-message

OPTIONS_DEFINE=				DOCS NCURSES PAR2
OPTIONS_DEFAULT=			NCURSES PAR2

PAR2_DESC=					PAR 2.0 compatible file verification and repair. Disable if you have trouble when compiling par2 module

NCURSES_USES=	ncurses

NCURSES_CMAKE_BOOL_OFF=		DISABLE_CURSES
PAR2_CMAKE_BOOL_OFF=		DISABLE_PARCHECK
CMAKE_TESTING_ON=			ENABLE_TESTS

.include <bsd.port.options.mk>

.if (${ARCH} == "i386")
CMAKE_ARGS+=		-DDISABLE_SIGCHLD_HANDLER=ON
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/nzbget.conf \
		${STAGEDIR}${PREFIX}/etc/nzbget.conf.sample

.include <bsd.port.mk>
