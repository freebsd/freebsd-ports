# $FreeBSD$

PORTNAME=	erkale-pseudopotentials
DISTVERSION=	g20190114
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pseudopotentials for Erkale, the quantum chemistry program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	susilehtola
GH_PROJECT=	erkale
GH_TAGNAME=	0c285c1

NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	${LOCALBASE}/share/erkale

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} basis ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
