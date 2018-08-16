# Created by: bauerm
# $FreeBSD$

PORTNAME=	ntl
PORTVERSION=	11.2.1
CATEGORIES=	math
MASTER_SITES=	http://www.shoup.net/ntl/

MAINTAINER=	ndowens@yahoo.com
COMMENT=	Victor Shoup's Number Theory Library

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/../doc/copying.txt

USES=		perl5 libtool
USE_LDCONFIG=	yes
USE_PERL5=	build
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	AR="${AR}" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		DEF_PREFIX="${LOCALBASE}" \
		LDFLAGS="${LDFLAGS}" PREFIX="${PREFIX}" \
		RANLIB="${RANLIB}" SHARED=on

CFLAGS+=	-fPIC
WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKEFILE=	makefile

OPTIONS_DEFINE=	DOCS GMP
OPTIONS_DEFAULT=	GMP

GMP_DESC=		Arbitrary precision arithmetic(Faster)
GMP_CONFIGURE_OFF=	NTL_GMP_LIP=off
GMP_LIB_DEPENDS=	libgmp.so:math/gmp

NTLDOCSDIR=		share/doc/NTL
PLIST_SUB=		NTLDOCS=${NTLDOCSDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${STAGEDIR}${DOCSDIR}

test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
