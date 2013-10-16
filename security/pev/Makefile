# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pev
PORTVERSION=	0.60
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	PE analysis toolkit

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USES=	gmake
USE_LDCONFIG=	yes

MAKE_ARGS+=	PREFIX=${STAGEDIR}/${PREFIX} MAKE=${GMAKE}

.include <bsd.port.mk>
