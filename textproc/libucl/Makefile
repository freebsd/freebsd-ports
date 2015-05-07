# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libucl
PORTVERSION=	0.7.3
PORTREVISION=	1
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
UTILS_DESC=		Install utilities: chargen, ucldump

LUA_USES=		lua
LUA_CONFIGURE_ENABLE=	lua

REGEX_CONFIGURE_ENABLE=	regex

SIGNATURES_USE=			OPENSSL=yes
SIGNATURES_CONFIGURE_ENABLE=	signatures
SIGNATURES_CPPFLAGS=		-I${OPENSSLINC}
SIGNATURES_LDFLAGS=		-L${OPENSSLLIB}

URLS_CONFIGURE_ENABLE=	urls
UTILS_CONFIGURE_ENABLE=	utils

USES=		autoreconf gmake libtool pathfix pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-silent-rules

GH_ACCOUNT=	vstakhov

PATHFIX_MAKEFILEIN=	Makefile.am
INSTALL_TARGET=		install-strip
CONFLICTS_INSTALL=	ucl

regression-test: build
	@cd ${WRKSRC} && ${MAKE} check
	
.include <bsd.port.mk>
