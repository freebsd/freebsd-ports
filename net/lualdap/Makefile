PORTNAME=	lualdap
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
PORTREVISION=	0
CATEGORIES=	net
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	p.mousavizadeh@protonmail.com
COMMENT=	LDAP support for the Lua language
WWW=		https://github.com/lualdap/lualdap

LICENSE=	MIT

USES=		gmake ldap lua:module
USE_GITHUB=	yes
USE_CSTD=	c99

MAKE_ARGS+=	CPPFLAGS="-I${LOCALBASE}/include -I${LUA_INCDIR}" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		CC="${CC}"

ALL_TARGET=

DOCSDIR=	${LUA_DOCSDIR}
OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/lualdap.so ${STAGEDIR}${LUA_MODLIBDIR}/${PORTNAME}.so

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
