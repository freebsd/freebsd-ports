# Created by: Johannes M Dieterich <jmd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xtb
PORTVERSION=	6.3.3
DISTVERSIONPREFIX=	v
CATEGORIES=	science

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Semiempirical Extended Tight-Binding Program Package

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fortran cmake blaslapack:openblas

USE_GITHUB=	yes
GH_ACCOUNT=	grimme-lab

USE_LDCONFIG=	yes
FFLAGS+=	-std=legacy

.include <bsd.port.mk>
