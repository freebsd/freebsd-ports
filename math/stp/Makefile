PORTNAME=	stp
DISTVERSION=	2.3.3
PORTREVISION=	12
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

USES=		bison:build compiler:c++11-lang cmake perl5 python
USE_GITHUB=	yes
USE_PERL5=	build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
