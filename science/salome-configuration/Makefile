PORTNAME=	salome-configuration
DISTVERSIONPREFIX=	V
DISTVERSION=	9_15_0
CATEGORIES=	science # physics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Salome Project: Multi-physics simulations: Configuration
WWW=		https://www.salome-platform.org/ \
		https://github.com/SalomePlatform/configuration/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	SalomePlatform
GH_PROJECT=	configuration

DATADIR=	${PREFIX}/share/salome
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/configuration
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/configuration
	${RM} ${STAGEDIR}${DATADIR}/configuration/.gitignore

.include <bsd.port.mk>
