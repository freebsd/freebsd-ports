PORTNAME=	libcifpp
DISTVERSIONPREFIX=	v
DISTVERSION=	7.0.4
CATEGORIES=	science
MASTER_SITES=	https://files.wwpdb.org/pub/pdb/data/monomers/:components
DISTFILES=	components.cif.gz:components
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	${GH_ACCOUNT}-${GH_PROJECT}-${DISTVERSIONFULL}_GH0${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to manipulate mmCIF and PDB files
WWW=		https://github.com/PDB-REDO/libcifpp

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	catch>0:devel/catch
LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs
RUN_DEPENDS=	bash:shells/bash

USES=		cmake:testing compiler:c++20-lang eigen:3 shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	PDB-REDO

SHEBANG_FILES=	tools/update-libcifpp-data.in

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DDISTDIR_FULL=${DISTDIR}/${DIST_SUBDIR}
CMAKE_TESTING_ON=	ENABLE_TESTING

post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${RM} -r var etc/libcifpp etc/periodic
	@${RM} -r ${STAGEDIR}/var/cache/libcifpp

.include <bsd.port.mk>
