# $FreeBSD$

PORTNAME=	libcint
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.14
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	General GTO integrals for quantum chemistry

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libopenblas.so:math/openblas

USES=		cmake blaslapack:openblas
USE_GITHUB=	yes
GH_ACCOUNT=	sunqm
USE_LDCONFIG=	yes

PLIST_FILES=	include/cint.h \
		lib/libcint.so \
		lib/libcint.so.${PORTVERSION}

.include <bsd.port.mk>
