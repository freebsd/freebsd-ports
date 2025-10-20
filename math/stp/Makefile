PORTNAME=	stp
DISTVERSION=	2.3.4
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	math

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Decision Procedure for Bitvectors and Arrays
WWW=		https://stp.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libminisat.so:math/minisat \
		libcryptominisat5.so:math/cryptominisat

USES=		bison:build cmake perl5 python
USE_GITHUB=	yes
GH_TAGNAME=	${DISTVERSION}_cadical
USE_PERL5=	build
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DUSE_CADICAL=OFF

.include <bsd.port.mk>
