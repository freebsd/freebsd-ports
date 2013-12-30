# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pev
PORTVERSION=	0.70
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	PE analysis toolkit

LICENSE=	GPLv3

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

WRKSRC=	${WRKDIR}/${PORTNAME}

USES=	gmake
USE_LDCONFIG=	yes

MAKE_ARGS=	MAKE=${GMAKE}
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
