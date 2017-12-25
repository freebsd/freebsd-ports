# Created by: Jin-Sih Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	phalcon
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.0
CATEGORIES=	www

MAINTAINER=	linpct@gmail.com
COMMENT=	Phalcon PHP Framework written in C-language

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=		amd64 armv6 armv7 i386

USES=		php:ext
USE_PHP=	hash:build json:build pdo:build

USE_GITHUB=	yes
GH_ACCOUNT=	phalcon
GH_PROJECT=	c${PORTNAME}

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-phalcon

.include <bsd.port.pre.mk>

PBITS=		${ARCH:S/amd64/64/:C/armv.*/32/:S/i386/32/:S/x86_64/64/}
WRKSRC_SUBDIR=	build/php${PHP_VER:C/.$//}/${PBITS}bits

post-patch:
.if ${PHP_VER} >= 70 && ${PBITS} == 32
	@${REINPLACE_CMD} -e 's| ZEPHIR_FASTCALL | |' ${WRKSRC}/phalcon.zep.c
.endif

.include <bsd.port.post.mk>
