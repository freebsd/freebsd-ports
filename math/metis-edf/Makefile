# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	metis-edf
DISTVERSION=	5.1.0-aster4
PORTEPOCH=	1
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Meshes partitioning tool used by Code_Aster

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

CONFLICTS=	metis-[0-9]* metis4-4*

USES=		cmake:noninja

PICFLAG?=	-fPIC
SHLIB_MAJOR?=	2
CMAKE_ARGS=	-DSHARED=1 -DSHLIB_MAJOR="${SHLIB_MAJOR}"	\
		-DGKLIB_PATH="${WRKSRC}/GKlib"

WRKSRC=		${WRKDIR}/${PORTNAME:C|-edf||}-${PORTVERSION:R}

DOCS=		Changelog manual/manual.pdf

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../french/aster/bsd.aster.mk"

MACHINEARCH=	${ARCH}
USE_LDCONFIG=	yes

pre-configure:
	# Borrowed from math/metis
	${REINPLACE_CMD} -e "/^# Add compiler flags/,/^$$/d" \
		-e "/^check_include_file(execinfo.h/d" \
		${WRKSRC}/GKlib/GKlibSystem.cmake
	${REINPLACE_CMD} -e "\|/home/karypis/|d" \
		${WRKSRC}/programs/CMakeLists.txt

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
. for df in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${df} ${STAGEDIR}${DOCSDIR}
. endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/graphs/* ${STAGEDIR}${EXAMPLESDIR}

do-test:
	(cd ${WRKSRC}/graphs && ../programs/gpmetis test.mgraph 2 || ${TRUE})

.include <bsd.port.post.mk>
