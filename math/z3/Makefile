# $FreeBSD$

PORTNAME=	z3
PORTVERSION=	4.4.0
CATEGORIES=	math

MAINTAINER=	6yearold@gmail.com
COMMENT=	Z3 Theorem Prover

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	Z3Prover
GH_TAGNAME=	z3-${PORTVERSION}

OPTIONS_DEFINE=		STATIC

OPTIONS_DEFAULT=	STATIC
OPTIONS_SUB=		yes

STATIC_DESC=		Build static z3 library
STATIC_CONFIGURE_ON=	--staticlib

GMP_DESC=		Use GMP library for AP arithmetic
GMP_CONFIGURE_ON=	--gmp
GMP_CXXFLAGS=		-I${LOCALBASE}include
GMP_LDFLAGS=		-L${LOCALBASE}/lib
GMP_LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp

HAS_CONFIGURE=		yes
USE_LDCONFIG=		yes
BUILD_WRKSRC=		${WRKSRC}/build
INSTALL_WRKSRC=		${WRKSRC}/build

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--debug
.endif

USES=		python

pre-build:
	${MKDIR} ${STAGEDIR}/${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
