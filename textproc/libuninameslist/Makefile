# Created by: KANOU Hiroki <kanou@khdd.net>
# $FreeBSD$

PORTNAME=	libuninameslist
PORTVERSION=	20091231
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20sources/Unicode_5.2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of Unicode annotation data

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake tar:bzip2 libtool
GNU_CONFIGURE=	yes
ALL_TARGET=	both
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
