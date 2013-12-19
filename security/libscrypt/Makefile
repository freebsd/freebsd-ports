# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	libscrypt
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	horia@racoviceanu.com
COMMENT=	C library for the scrypt key derivation function

LICENSE=	BSD2CLAUSE

USES=		compiler
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	technion
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	8e6966e

PLIST_FILES=	include/libscrypt.h \
		lib/libscrypt.a \
		lib/libscrypt.so \
		lib/libscrypt.so.0

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^CC=gcc/d' -e '/CFLAGS=/s|$$| ${CFLAGS}|' \
		-e 's|/usr/local|${PREFIX}| ; \
		s|install: library|& install-static| ; \
		s|$$(LDFLAGS)||' ${WRKSRC}/Makefile

regression-test: build
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check)

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.pre.mk>

.if ${ARCH} == i386 && ${COMPILER_TYPE} == gcc
CFLAGS+=	-fno-stack-protector
.endif

.include <bsd.port.post.mk>
