# $FreeBSD$

PORTNAME=	frand
PORTVERSION=	0.1
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	serpent7776@gmail.com
COMMENT=	Selects a random file using reservoir sampling algorithm

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs

USES=		cmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	serpent7776
GH_TUPLE=	LiorKogan:StreamSampler:919a0f1ba6bb3ae63b4708722e9a7d49164ca92d:StreamSampler/lib/StreamSampler

.include <bsd.port.mk>
