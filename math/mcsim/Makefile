# Created by: Alessando Sagratini <ale_sagra@hotmail.com>
# $FreeBSD$

PORTNAME=	mcsim
PORTVERSION=	6.1.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	ale_sagra@hotmail.com
COMMENT=	Monte Carlo stochastic simulations and Bayesian inference

LICENSE=	GPLv3+

BUILD_DEPENDS=	indexinfo>=0.3.0:print/indexinfo

USES=		libtool shebangfix

USE_LDCONFIG=	yes

INFO=		mcsim

SHEBANG_FILES=	sim/makemcsim.in sim/makemcsims.in sim/makemcsimd.in

INSTALL_TARGET=	install-strip

GNU_CONFIGURE=	yes
OPTIONS_SUB=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

OPTIONS_DEFINE=	GSL SUNDIALS
GSL_DESC=	GNU Scientific Library support (recommended)
SUNDIALS_DESC=	Sundial's Cvodes integrator

OPTIONS_DEFAULT=GSL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSUNDIALS}
BUILD_DEPENDS+=	sundials>=3.0.0:math/sundials
.endif

.if ${PORT_OPTIONS:MGSL}
BUILD_DEPENDS+=	gsl>=2.5:math/gsl
.endif

.include <bsd.port.mk>
