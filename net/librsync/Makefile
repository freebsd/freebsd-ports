# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librsync
PORTVERSION=	2.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for delta compression of streams

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt

USES=		cmake compiler:c11 perl5
USE_PERL5=	test

USE_GITHUB=	yes

TEST_TARGET=	check
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
