# $FreeBSD$

PORTNAME=	pev
PORTVERSION=	0.60
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	The PE analysis toolkit

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USES=	gmake
USE_LDCONFIG=	yes

MAKE_ARGS+=	PREFIX=${STAGEDIR}/${PREFIX} MAKE=${GMAKE}

.include <bsd.port.mk>
