# $FreeBSD$

PORTNAME=	lean
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.2
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Theorem prover

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	leanprover
USE_LDCONFIG=	yes

WRKSRC_SUBDIR=	src

PORTSCOUT=	limit:.*[0-9]+\.[0-9]+$$

.include <bsd.port.mk>
