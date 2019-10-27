# Created by: bauerm
# $FreeBSD$

PORTNAME=	ntl
PORTVERSION=	11.4.1
CATEGORIES=	math
MASTER_SITES=	http://www.shoup.net/ntl/

MAINTAINER=	ndowens04@gmail.com
COMMENT=	Victor Shoup's Number Theory Library

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/../doc/copying.txt

USES=		compiler:c11 libtool perl5
USE_LDCONFIG=	yes
USE_PERL5=	build

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=AR="${AR}" CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		DEF_PREFIX="${LOCALBASE}" LDFLAGS="${LDFLAGS}" \
		PREFIX="${PREFIX}" RANLIB="${RANLIB}" SHARED=on

CFLAGS+=	-fPIC
WRKSRC_SUBDIR=	src
MAKEFILE=	makefile
TEST_TARGET=	check

NTLDOCSDIR=	share/doc/NTL
PLIST_SUB=	NTLDOCS=${NTLDOCSDIR}

OPTIONS_DEFINE=		DOCS GMP
OPTIONS_DEFAULT=	GMP

GMP_DESC=		Arbitrary precision arithmetic(Faster)
GMP_LIB_DEPENDS=	libgmp.so:math/gmp
GMP_CONFIGURE_OFF=	NTL_GMP_LIP=off

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${STAGEDIR}${DOCSDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libntl.so.*

.include <bsd.port.mk>
