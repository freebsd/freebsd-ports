# Created by: gahr
# $FreeBSD$

PORTNAME=	abacus
DISTVERSION=	3.2betaU1
PORTREVISION=	9
CATEGORIES=	math
MASTER_SITES=	http://www.informatik.uni-koeln.de/abacus/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Branch-And-CUt System

LICENSE=	LGPL21+

DEPRECATED=	Unmaintained and has a broken shared library
EXPIRATION_DATE=2018-03-31

LIB_DEPENDS=	libClp.so:math/coinmp

NO_WRKSUBDIR=	yes

USES=		gmake perl5
USE_PERL5=	build
USE_LDCONFIG=	yes
ALL_TARGET=	abacus
CXXFLAGS+=	-fPIC
MAKE_ARGS=	CCC="${CXX}" PERL="${PERL}" STRIP="${STRIP_CMD} -x" \
		ARCHIVE="${AR} ${ARFLAGS}" CCFLAG_DEBOPT="${CXXFLAGS}" \
		OSI_INCLUDE="${LOCALBASE}/include/coin"

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/linux20-gcc44/libabacus-osi.a \
		${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib/linux20-gcc44/libabacus-osi.so.1 \
		${STAGEDIR}${PREFIX}/lib
	${LN} -sf libabacus-osi.so.1 \
		${STAGEDIR}${PREFIX}/lib/libabacus-osi.so
	(cd ${WRKSRC}/Include && ${COPYTREE_SHARE} abacus \
		${STAGEDIR}${PREFIX}/include)

.include <bsd.port.mk>
