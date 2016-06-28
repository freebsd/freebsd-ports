# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	scrypt
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	security pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP wrapper to Colin Percival's scrypt implementation

LICENSE=	BSD2CLAUSE

BROKEN_powerpc64=	Does not build

USES=		compiler php:ext tar:tgz
USE_PHP=	hash:build
INSTALL_TARGET=	install-strip
IGNORE_WITH_PHP=	70

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	README.md

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
PORTEXAMPLES=	scrypt.php

TESTDIR=	${PREFIX}/tests/${PKGNAMEPREFIX}${PORTNAME}
PORTTEST=	run-tests.php tests/params.phpt tests/vectors.phpt

OPTIONS_DEFINE=	DOCS EXAMPLES TEST

TEST_PLIST_FILES=	${PORTTEST:S|^|${TESTDIR:S|${PREFIX}/||:S|$|/|}|}

.include <bsd.port.pre.mk>

.if ${ARCH} == i386 && ${OSVERSION} < 1000036
CFLAGS+=	-fstack-protector
.endif

.if ${ARCH} != amd64 && ${COMPILER_TYPE} == gcc
post-patch:
	${REINPLACE_CMD} '/emmintrin.h/d' ${WRKSRC}/config.m4
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}

.if ${PORT_OPTIONS:MTEST}
	@${MKDIR} ${STAGEDIR}${TESTDIR}
	${INSTALL_DATA} ${PORTTEST:M*.php:S|^|${WRKSRC}/|} ${STAGEDIR}${TESTDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} tests ${STAGEDIR}${TESTDIR})
.endif

.include <bsd.port.post.mk>
