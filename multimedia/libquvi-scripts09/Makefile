# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libquvi-scripts
PORTVERSION=	0.9.20131130
PORTREVISION=	1
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/quvi/${PORTVERSION}/${PORTNAME}/ \
		LOCAL/sunpoet
PKGNAMESUFFIX=	09

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Embedded lua scripts for libquvi and utility scripts

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}bitop>=1.0.1:devel/lua-bitop \
		${LUA_PKGNAMEPREFIX}luaexpat>=1.2.0:textproc/luaexpat \
		${LUA_PKGNAMEPREFIX}json>=1.1.1:converters/lua-json \
		${LUA_PKGNAMEPREFIX}luasocket>=2.0.2:net/luasocket

OPTIONS_DEFINE=	NSFW
OPTIONS_SUB=	yes
NSFW_DESC=	Enable adult website support

CONFIGURE_ARGS=	--program-suffix=${PKGNAMESUFFIX}
GNU_CONFIGURE=	yes
NO_ARCH=	yes
USES=		lua:run pathfix tar:xz

PLIST_SUB=	PKGNAMESUFFIX=${PKGNAMESUFFIX} PORTVERSION=${PORTVERSION} QUVIVERSION=${PORTVERSION:R}

NSFW_CONFIGURE_WITH=	nsfw

.include <bsd.port.mk>
