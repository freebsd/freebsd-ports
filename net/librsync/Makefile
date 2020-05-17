# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librsync
PORTVERSION=	2.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for delta compression of streams

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt

USES=		cmake compiler:c11 localbase:ldflags

USE_GITHUB=	yes

USE_LDCONFIG=	yes

TEST_TARGET=	check

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
