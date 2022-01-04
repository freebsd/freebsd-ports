PORTNAME=	oink
DISTVERSION=	g20210704
PORTREVISION=	1
CATEGORIES=	math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	cd8c62bc1900ffee6d933fa31cbdd954560c286b.patch:-p1 # Fix build on FreeBSD
PATCHFILES+=	a5c10784a472c42bab5a4df0ef29799011bc30b1.patch:-p1 # Fix installed cmake file path

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern parity game solvers written in C++

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs

USES=		cmake:testing
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	trolando
GH_TAGNAME=	c1259fe

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
