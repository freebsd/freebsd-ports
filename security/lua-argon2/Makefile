PORTNAME=	argon2
DISTVERSION=	3.0.1
CATEGORIES=	security
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	mdw@FreeBSD.org
COMMENT=	Lua C binding for the Argon2 password hashing function
WWW=		https://github.com/thibaultcha/lua-argon2

LICENSE=	MIT

LIB_DEPENDS+=	libargon2.so:security/libargon2

USES=		compiler:c11 lua:module

USE_GITHUB=	yes
GH_ACCOUNT=	thibaultcha
GH_PROJECT=	lua-argon2

PLIST_FILES=	${LUA_MODLIBDIR}/argon2.so

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/argon2.so ${STAGEDIR}${LUA_MODLIBDIR}

.include <bsd.port.mk>
