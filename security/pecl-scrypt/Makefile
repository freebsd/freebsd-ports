# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	scrypt
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	security pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz

MAINTAINER=	horia@racoviceanu.com
COMMENT=	PHP wrapper to Colin Percival's scrypt implementation

LICENSE=	BSD2CLAUSE

USES=		compiler
USE_PHP=	hash
USE_PHPEXT=	yes
USE_PHP_BUILD=	yes

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=STACKPROTECTOR

OPTIONS_RADIO=	BUFFER_OVERFLOW_PROTECTION
OPTIONS_RADIO_BUFFER_OVERFLOW_PROTECTION=	STACKPROTECTOR STACKPROTECTORALL

STACKPROTECTOR_DESC=	Protect functions with vulnerable objects
STACKPROTECTORALL_DESC=	Protect all functions

STACKPROTECTOR_CFLAGS=	-fstack-protector
STACKPROTECTORALL_CFLAGS=	-fstack-protector-all

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64 && ${COMPILER_TYPE} == gcc
post-patch:
	${REINPLACE_CMD} '/emmintrin.h/d' ${WRKSRC}/config.m4
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/${PORTNAME}.so

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
