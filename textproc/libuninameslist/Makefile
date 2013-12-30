# Created by: KANOU Hiroki <kanou@khdd.net>
# $FreeBSD$

PORTNAME=	libuninameslist
PORTVERSION=	20091231
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20sources/Unicode_5.2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library of Unicode annotation data

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USES=		gmake
USE_AUTOTOOLS=	libtool
ALL_TARGET=	both
USE_LDCONFIG=	yes

.include <bsd.port.mk>
