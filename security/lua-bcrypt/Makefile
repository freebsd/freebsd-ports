# $FreeBSD$

PORTNAME=	bcrypt
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1-4
PORTREVISION=	1
CATEGORIES=	security
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	mdw@FreeBSD.org
COMMENT=	Library providing OpenBSD's bcrypt hash function for Lua

LICENSE=	ISCL

USES=		compiler:c11 gmake lua

USE_GITHUB=	yes
GH_ACCOUNT=	mikejsavage
GH_PROJECT=	lua-bcrypt

PLIST_FILES=	${LUA_MODLIBDIR}/bcrypt.so

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/bcrypt.so ${STAGEDIR}${LUA_MODLIBDIR}

.include <bsd.port.mk>
