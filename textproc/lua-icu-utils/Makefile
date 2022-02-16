# Created by: Martin Matuska <mm@FreeBSD.org>

PORTNAME=	icu-utils
DISTVERSION=	0.0-20160816
CATEGORIES=	textproc
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Lua interface to selected ICU utilities

LICENSE=	MIT

LIB_DEPENDS=	libicui18n.so:devel/icu

USES=		gmake lua:module

USE_GITHUB=	yes
GH_ACCOUNT=	adam-stanek
GH_PROJECT=	lua_icu_utils
GH_TAGNAME=	df830c0

CFLAGS+=	-fPIC -I${LOCALBASE}/include
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="-shared -L${LOCALBASE}/lib" LUA_INCDIR="${LUA_INCDIR}"

PLIST_FILES=	${LUA_MODLIBDIR}/icu_utils.so
PORTDOCS=	README.md

DOCSDIR=	${PREFIX}/share/doc/lua${LUA_VER_STR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/icu_utils.so ${STAGEDIR}${LUA_MODLIBDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
