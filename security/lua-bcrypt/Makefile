# $FreeBSD$

PORTNAME=	bcrypt
DISTVERSION=	2.1-4
CATEGORIES=	security
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	mdw@freebsd.org
COMMENT=	Library providing OpenBSD's bcrypt hash function for Lua

LICENSE=	ISCL

USES=		compiler:c11 gmake lua

USE_GITHUB=	yes
GH_ACCOUNT=	mikejsavage
GH_PROJECT=	lua-bcrypt
GH_TAGNAME=	v2.1-4

PLIST_FILES=	${LUA_MODLIBDIR}/bcrypt.so

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/bcrypt.so ${STAGEDIR}${LUA_MODLIBDIR}

.include <bsd.port.mk>
