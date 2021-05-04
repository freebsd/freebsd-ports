PORTNAME=	minizinc-solvers
PORTVERSION=	20210505
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Metaport for MiniZinc solvers

USES=		metaport

OPTIONS_MULTI=		LIST
OPTIONS_MULTI_LIST=	BONMIN CHUFFED COUENNE JACOP GECODE OR_TOOLS
OPTIONS_DEFAULT=	${OPTIONS_MULTI_LIST}

LIST_DESC=		Install:

BONMIN_DESC=		Nonlinear mixed integer programming solver (COIN-OR)
BONMIN_RUN_DEPENDS=	coin-or-bonmin>0:math/bonmin

CHUFFED_DESC=		Chuffed lazy clause generation CP solver
CHUFFED_RUN_DEPENDS=	chuffed>0:math/chuffed

COUENNE_DESC=		Nonlinear convex over and under envelopes solver (COIN-OR)
COUENNE_RUN_DEPENDS=	coin-or-couenne>0:math/couenne

JACOP_DESC=		Java Constraint Programming solver
JACOP_RUN_DEPENDS=	jacop>0:math/jacop

GECODE_DESC=		Gecode solver
GECODE_RUN_DEPENDS=	gecode>0:math/gecode

OR_TOOLS_DESC=		Google OR-Tools-based solver
OR_TOOLS_RUN_DEPENDS=	or-tools>0:math/or-tools

.include <bsd.port.mk>
