PORTNAME=	maeparser
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Parser for Schrodinger Maestro files
WWW=		https://github.com/schrodinger/maeparser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs

USES=		cmake:testing compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	schrodinger
USE_LDCONFIG=	yes

# 100% tests passed, 0 tests failed out of 1

.include <bsd.port.mk>
