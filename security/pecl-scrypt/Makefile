# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	scrypt
PORTVERSION=	1.2
CATEGORIES=	security pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz

MAINTAINER=	horia@racoviceanu.com
COMMENT=	PHP wrapper to Colin Percival's scrypt implementation

LICENSE=	BSD

USE_PHP=	hash
USE_PHPEXT=	yes
USE_PHP_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64
post-patch:
	${REINPLACE_CMD} '/emmintrin.h/d' ${WRKSRC}/config.m4
.endif

.include <bsd.port.post.mk>
