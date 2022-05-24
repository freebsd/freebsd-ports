PORTNAME=	erkale-pseudopotentials
DISTVERSION=	g20220405
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pseudopotentials for Erkale, the quantum chemistry program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	susilehtola
GH_PROJECT=	erkale
GH_TAGNAME=	f005a9ed588d7b6fcda54648db16523419308cbd

NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	${LOCALBASE}/share/erkale

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} basis ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
