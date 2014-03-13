# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	libscrypt
PORTVERSION=	1.18
CATEGORIES=	security

MAINTAINER=	horia@racoviceanu.com
COMMENT=	C library for the scrypt key derivation function

LICENSE=	BSD2CLAUSE

USES=		compiler
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	technion
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	35b6894

PLIST_FILES=	include/libscrypt.h \
		lib/libscrypt.so \
		lib/libscrypt.so.0

PORTDOCS=	README.md
OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|CC?=gcc|CC?=${CC}|; s|CFLAGS?=|CFLAGS+=|; \
		s|LIBDIR       ?|LIBDIR        |' ${WRKSRC}/Makefile

.if ${ARCH} == i386 && ${COMPILER_TYPE} == gcc
	@${REINPLACE_CMD} -e 's|stack-protector|no-&|' ${WRKSRC}/Makefile
.endif

regression-test: build
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check)

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so.0

.include <bsd.port.post.mk>
