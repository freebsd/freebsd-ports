PORTNAME=	apbs
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.5-102
DISTVERSIONSUFFIX=	-g500c1473
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Electrostatic and solvation properties for complex molecules

LICENSE=	MIT

USES=		cmake shebangfix
SHEBANG_FILES=	tools/github/getReleases.sh
USE_GITHUB=	yes
GH_ACCOUNT=	Electrostatics
GH_PROJECT=	apbs-pdb2pqr
GH_TUPLE=	Electrostatics:FETK:0c6fdea:fetk/externals/fetk \
		Electrostatics:geoflow_c:e8ce510:geoflow_c/externals/geoflow_c \
		lwwilson1:TABIPB:7e3a407:bem/externals/bem \
		lwwilson1:mesh_routines:ddb75cb:mr/externals/mesh_routines \
		davas301:pb_solvers:4858465:ps/externals/pb_s_am
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

# Fix build on recent current with clang11
CFLAGS+=	-fcommon

WRKSRC_SUBDIR=	${PORTNAME}

post-stage: # https://github.com/Electrostatics/apbs-pdb2pqr/issues/522
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/apbs/tools/bin/*

.include <bsd.port.mk>
