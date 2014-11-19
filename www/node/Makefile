# Created by: Jin-Sih Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	node
PORTVERSION=	0.10.33
CATEGORIES=	www
MASTER_SITES=	http://nodejs.org/dist/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	linpct@gmail.com
COMMENT=	V8 JavaScript for client and server

LICENSE=	MIT

USES=		gmake compiler execinfo python:2
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFLICTS=	node-0.[02-9][0-9]* node-devel-0.[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
CONFIGURE_ARGS=	--prefix=${PREFIX_RELDEST} --without-npm --shared-zlib
PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}
REINPLACE_ARGS=	-i ''
MAKE_ENV+=	CC.host=${CC} CXX.host=${CXX} LINK.host=${CXX} LINK.target=${CXX}

.include <bsd.port.pre.mk>
.if ${COMPILER_TYPE} == clang
MAKE_ENV+=	LINK=clang++
CFLAGS+=	-Wno-unused-private-field
.if ${COMPILER_VERSION} >= 33
CFLAGS+=	-Wno-nested-anon-types -Wno-unused-function
.if ${COMPILER_VERSION} >= 34
CFLAGS+=	-Wno-unused-const-variable
.endif
.endif
.else
MAKE_ARGS+=	strictaliasing=off
USE_GCC=	any
.endif

post-patch:
	@${REINPLACE_CMD} -e '1 s|${SETENV} python|${PYTHON_CMD}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|'python',|'${PYTHON_CMD}',|" \
		${WRKSRC}/deps/v8/build/common.gypi \
		${WRKSRC}/deps/v8/tools/gyp/v8.gyp \
		${WRKSRC}/deps/v8/src/d8.gyp
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/deps/v8/build/common.gypi \
		${WRKSRC}/deps/v8/tools/gyp/v8.gyp

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/
	${TOUCH} ${STAGEDIR}${PREFIX}/lib/node_modules/.keepme
	${CHMOD} ${MANMODE} ${STAGEDIR}${PREFIX}/man/man1/node.1

.include <bsd.port.post.mk>
