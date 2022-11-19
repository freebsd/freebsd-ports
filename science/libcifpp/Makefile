PORTNAME=	libcifpp
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.3
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.wwpdb.org/pub/pdb/data/monomers/:components
DISTFILES=	components.cif.gz:components
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	${GH_ACCOUNT}-${GH_PROJECT}-${DISTVERSIONFULL}_GH0${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to manipulate mmCIF and PDB files
WWW=		https://github.com/PDB-REDO/libcifpp

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails: static_assert failed due to requirement 'sizeof(cif::item_value) == 16', see https://github.com/PDB-REDO/libcifpp/issues/25

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs
RUN_DEPENDS=	bash:shells/bash

USES=		cmake:testing compiler:c++17-lang shebangfix
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

.include <bsd.port.mk>
