# Created by: Jin-Sih Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	phalcon
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.5
CATEGORIES=	www
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	franco@opnsense.org
COMMENT=	Phalcon PHP Framework written in C-language

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=		aarch64 amd64 armv6 armv7 i386

CONFLICTS_INSTALL=	${PKGNAMEPREFIX}phalcon4

USES=		php:ext
USE_PHP=	hash:build json:build pdo:build
IGNORE_WITH_PHP=	74

USE_GITHUB=	yes
GH_ACCOUNT=	phalcon
GH_PROJECT=	c${PORTNAME}

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-phalcon

.include <bsd.port.pre.mk>

PBITS=		${ARCH:S/aarch64/64/:S/amd64/64/:C/armv.*/32/:S/i386/32/:S/x86_64/64/}
WRKSRC_SUBDIR=	build/php${PHP_VER:C/.$//}/${PBITS}bits

post-patch:
.if ${PBITS} == 32
	@${REINPLACE_CMD} -e 's|ZEPHIR_FASTCALL| |' ${WRKSRC}/phalcon.zep.c
.endif

.include <bsd.port.post.mk>
