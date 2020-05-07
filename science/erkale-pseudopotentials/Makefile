# $FreeBSD$

PORTNAME=	erkale-pseudopotentials
DISTVERSION=	g20200426
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pseudopotentials for Erkale, the quantum chemistry program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	susilehtola
GH_PROJECT=	erkale
GH_TAGNAME=	870e772f09631b3dbdd99a18e4f3d4786d684a01

NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	${LOCALBASE}/share/erkale

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} basis ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
