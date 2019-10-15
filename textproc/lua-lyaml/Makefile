# Created by: Yarema <yds@Necessitu.de>
# $FreeBSD$

PORTNAME=	lyaml
PORTVERSION=	6.2.4
DISTVERSIONPREFIX=v
CATEGORIES=	textproc
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	yds@Necessitu.de
COMMENT=	LibYAML binding for Lua

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libyaml.so:textproc/libyaml

USES=		lua

USE_GITHUB=	yes
GH_ACCOUNT=	gvvaughan
GH_PROJECT=	${PORTNAME}

CFLAGS+=	-pedantic -Wall -Qunused-arguments -fPIC -DPIC -std=c99\
		-fno-strict-aliasing -isystem ${LOCALBASE}/include\
		-I${LUA_INCDIR} -DVERSION=\"${PORTVERSION}\" -DNDEBUG\
		-D_FORTIFY_SOURCE=2 -D_BSD_SOURCE -D__BSD_VISIBLE
LDFLAGS+=	-shared -L${LOCALBASE}/lib

DOCSDIR=	${PREFIX}/share/doc/lua${LUA_VER_STR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC}/ext/yaml &&\
		${CC} ${CFLAGS} ${LDFLAGS} -lyaml -o yaml.so\
		yaml.c emitter.c parser.c scanner.c

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR} ${STAGEDIR}${LUA_MODSHAREDIR}/${PORTNAME}
	${INSTALL_LIB} ${WRKSRC}/ext/yaml/yaml.so ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}/*.lua ${STAGEDIR}${LUA_MODSHAREDIR}/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/modules
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/modules/*.* ${STAGEDIR}${DOCSDIR}/modules

.include <bsd.port.mk>
