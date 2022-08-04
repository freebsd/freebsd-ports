PORTNAME=	xtb
PORTVERSION=	6.4.1
DISTVERSIONPREFIX=	v
CATEGORIES=	science

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Semiempirical Extended Tight-Binding Program Package

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

USES=		fortran cmake blaslapack:openblas

USE_GITHUB=	yes
GH_ACCOUNT=	grimme-lab

USE_LDCONFIG=	yes
FFLAGS+=	-std=legacy

.include <bsd.port.mk>
