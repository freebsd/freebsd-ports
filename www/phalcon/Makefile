# Created by: Jin-Sih Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	phalcon
PORTVERSION=	3.0.3
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	linpct@gmail.com
COMMENT=	Phalcon PHP Framework written in C-language

LICENSE=	BSD3CLAUSE

USES=		php:ext
USE_PHP=	hash:build json:build pdo:build

ONLY_FOR_ARCHS=	amd64 armv6 i386

USE_GITHUB=	yes
GH_ACCOUNT=	phalcon
GH_PROJECT=	c${PORTNAME}

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-phalcon

.include <bsd.port.pre.mk>

PBITS=		${ARCH:S/amd64/64/:S/armv6/32/:S/i386/32/:S/x86_64/64/}
WRKSRC_SUBDIR=	build/php${PHP_VER:C/.$//}/${PBITS}bits

.include <bsd.port.post.mk>
