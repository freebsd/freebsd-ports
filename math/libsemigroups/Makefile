# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	libsemigroups
PORTVERSION=	1.0.9
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	C++ library for semigroups and monoids

LICENSE=	GPLv3

BUILD_DEPENDS=	HPCombi>0:math/hpcombi
LIB_DEPENDS=	libfmt.so:devel/libfmt

USE_GITHUB=	yes

USES=		autoreconf compiler:c++11-lang libtool pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-external-fmt=yes
USE_LDCONFIG=	yes
TEST_TARGET=	check

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64
CONFIGURE_ARGS+=	--disable-hpcombi
.endif

pre-configure:
.if ${ARCH} == amd64
	${REINPLACE_CMD} -e 's|$$srcdir/extern/HPCombi|${LOCALBASE}/share/HPCombi|'	\
		${WRKSRC}/m4/ax_check_hpcombi.m4
	${REINPLACE_CMD} -e 's|extern/HPCombi/include|${LOCALBASE}/include/HPCombi|'	\
		${WRKSRC}/Makefile.am
.endif
	${REINPLACE_CMD} -e 's|extern/HPCombi/include|HPCombi|'	\
		${WRKSRC}/include/libsemigroups/hpcombi.hpp
	${REINPLACE_CMD} -e 's|fmtinclude_HEADERS|#fmtinclude_HEADERS|'	\
		${WRKSRC}/Makefile.am

.include <bsd.port.post.mk>
