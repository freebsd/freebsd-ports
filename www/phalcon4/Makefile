PORTNAME=	phalcon
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1.3
CATEGORIES=	www
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
PKGNAMESUFFIX=	4

MAINTAINER=	franco@opnsense.org
COMMENT=	Phalcon PHP Framework written in C-language

LICENSE=	BSD3CLAUSE

DEPRECATED=Requires php 7.4 which is set to expire on 2022-11-29
EXPIRATION_DATE=2022-11-28

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc powerpc64 powerpc64le riscv64

RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/psr.so:devel/pecl-psr@${PHP_FLAVOR}

USES=		localbase php:ext
USE_GITHUB=	yes
GH_PROJECT=	c${PORTNAME}

USE_PHP=	json:build mbstring pdo:build session
IGNORE_WITH_PHP=	80 81
PHP_MOD_PRIO=	30

CONFIGURE_ARGS=	--enable-phalcon

CONFLICTS_INSTALL=	${PKGNAMEPREFIX}phalcon

.include <bsd.port.pre.mk>

PBITS=		${ARCH:S/aarch64/64/:S/amd64/64/:C/armv.*/32/:S/i386/32/:S/x86_64/64/:C/powerpc64.*/64/:S/powerpc/32/:C/riscv64.*/64/}
WRKSRC_SUBDIR=	build/php${PHP_VER:C/.$//}/${PBITS}bits

post-patch:
.if ${PBITS} == 32
	@${REINPLACE_CMD} -e 's|ZEPHIR_FASTCALL| |' ${WRKSRC}/phalcon.zep.c
.endif

.include <bsd.port.post.mk>
