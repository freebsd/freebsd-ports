# $FreeBSD$

PORTNAME=	z3-solver
DISTVERSIONPREFIX=	z3-
DISTVERSION=	4.8.7
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for Z3 Theorem Prover

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../../../LICENSE.txt

BROKEN_i386=	can't create dynamic relocation R_386_32 against symbol: .L.str in readonly segment; see https://github.com/Z3Prover/z3/issues/2442

# CAVEAT: There should have LIB_DEPENDS=libz3.so:math/z3, but currently it rebuilds all code, see https://github.com/Z3Prover/z3/issues/1767

USES=		compiler:c++11-lang python
USE_GITHUB=	yes
GH_ACCOUNT=	Z3Prover
GH_PROJECT=	z3
USE_PYTHON=	distutils autoplist

WRKSRC_SUBDIR=	src/api/python

post-patch: # https://github.com/Z3Prover/z3/issues/2131
	@${REINPLACE_CMD} 's|…|...|' ${WRKSRC}/../../ast/recfun_decl_plugin.h

.include <bsd.port.mk>
