# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pev
PORTVERSION=	0.70
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	PE analysis toolkit

LICENSE=	GPLv3

LIB_DEPENDS=	libpcre.so:devel/pcre

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake ssl
USE_LDCONFIG=	yes

MAKE_ARGS=	MAKE=${MAKE_CMD}
CFLAGS+=	-I${OPENSSLINC} -I${LOCALBASE}/include
LDFLAGS+=	-L${OPENSSLLIB}

.include <bsd.port.mk>
