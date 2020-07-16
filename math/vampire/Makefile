# $FreeBSD$

PORTNAME=	vampire
DISTVERSION=	4.5.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Automatic theorem prover

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		compiler:c++11-lang gmake
USE_GITHUB=	yes
GH_ACCOUNT=	vprover

ALL_TARGET=	vampire_rel # do we also need the z3 target?

BINARY_ALIAS=	g++=${CXX}

CXXFLAGS+=	-DCHECK_LEAKS=0
MAKE_ARGS=	FREEBSD_VERSION_NUMBER="${PORTVERSION}"

#MAKE_ARGS=	GNUMPF=1 # This causes compillation failure, additionally GitHub failed to create the issue for this project.

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${ALL_TARGET}* ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
