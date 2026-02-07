PORTNAME=	xtb
DISTVERSIONPREFIX=	v
DISTVERSION=	6.5.1
PORTREVISION=	4
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Semiempirical Extended Tight-Binding Program Package
WWW=		https://github.com/grimme-lab/xtb

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

LIB_DEPENDS=	libmctc-lib.so:science/mctc-lib
TEST_DEPENDS=	test-drive>0:devel/test-drive

USES=		blaslapack:openblas cmake:testing fortran blaslapack:openblas

USE_GITHUB=	yes
GH_ACCOUNT=	grimme-lab

USE_LDCONFIG=	yes
FFLAGS+=	-std=legacy

.include <bsd.port.mk>
