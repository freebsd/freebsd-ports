# Created by: Piotr Florczyk <pf@itwf.pl>
# $FreeBSD$

PORTNAME=	lualdap
PORTVERSION=	1.2.5
DISTVERSIONPREFIX=	v
CATEGORIES=	net
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LDAP support for the Lua language

LICENSE=        MIT

USES=		gmake lua:-52,module
USE_OPENLDAP=	yes
USE_GITHUB=	yes

MAKE_ARGS+=	CPPFLAGS="-I${LOCALBASE}/include -I${LUA_INCDIR}" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		CC="${CC}"

ALL_TARGET=

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${LUA_DOCSDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/lualdap.so ${STAGEDIR}${LUA_MODLIBDIR}/${PORTNAME}.so

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/us/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
