# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libucl
PORTVERSION=	0.8.0
CATEGORIES=	textproc devel

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Universal configuration library parser

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=		LUA REGEX SIGNATURES URLS UTILS
OPTIONS_DEFAULT=	REGEX UTILS
OPTIONS_SUB=		yes

REGEX_DESC=		Enable regex checking for schema
SIGNATURES_DESC=	Enable signatures checking
URLS_DESC=		Enable fetching URLs
UTILS_DESC=		Enable tools:  ucl_chargen, ucl_ucldump, ucl_tool

LUA_CONFIGURE_ENABLE=	lua
LUA_CONFIGURE_ENV=	LUA=${LOCALBASE}/bin/${LUA_CMD}
LUA_LDFLAGS=		-L${LUA_LIBDIR}
LUA_USES=		lua

REGEX_CONFIGURE_ENABLE=	regex

SIGNATURES_CONFIGURE_ENABLE=	signatures
SIGNATURES_CPPFLAGS=		-I${OPENSSLINC}
SIGNATURES_LDFLAGS=		-L${OPENSSLLIB}
SIGNATURES_USE=			OPENSSL=yes

URLS_CONFIGURE_ENABLE=	urls

UTILS_CONFIGURE_ENABLE=	utils

USES=		autoreconf gmake libtool pathfix pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

GH_ACCOUNT=	vstakhov

CONFLICTS_INSTALL=	ucl

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
