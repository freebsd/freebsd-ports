# $FreeBSD$

PORTNAME=	frand
PORTVERSION=	0.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	serpent7776@gmail.com
COMMENT=	Selects a random file using reservoir sampling algorithm

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	serpent7776
GH_PROJECT=	frand StreamSampler:StreamSampler
GH_TAGNAME=	919a0f1ba6bb3ae63b4708722e9a7d49164ca92d:StreamSampler
GH_ACCOUNT_StreamSampler=	LiorKogan
GH_SUBDIR_StreamSampler=	lib/StreamSampler

.include <bsd.port.mk>
