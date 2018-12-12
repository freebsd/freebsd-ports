# $FreeBSD$

PORTNAME=	quantum-espresso-pseudopotentials
DISTVERSION=	g20180406
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pseudopotentials for use with Quantum Espresso

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/License

BUILD_DEPENDS=	quantum-espresso>0:science/quantum-espresso \
		bash:shells/bash
RUN_DEPENDS=	quantum-espresso>0:science/quantum-espresso

USES=		shebangfix
SHEBANG_GLOB=	*.job make_*
SHEBANG_FILES=	QE_path clean clean_all
USE_GITHUB=	yes
GH_ACCOUNT=	dalcorso
GH_PROJECT=	pslibrary
GH_TAGNAME=	9dd5cf7

NO_ARCH=	yes

DATADIR=	${PREFIX}/share/quantum-espresso
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} 's|/path_to_quantum_espresso/|${LOCALBASE}|' ${WRKSRC}/QE_path

do-build:
	@cd ${WRKSRC} && ./make_all_ps

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${FIND} ${WRKSRC} -name "*.UPF" -and -exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR} \;

.include <bsd.port.mk>
