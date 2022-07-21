PORTNAME=	pytanque
DISTVERSION=	1.1.0
CATEGORIES=	math
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Petanque static python bindings

LICENSE=	BSD3CLAUSE

BROKEN_riscv64=	ld: error: lto.tmp: cannot link object files with different floating-point ABI

USES=		compiler:c++14-lang python:3.6+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
