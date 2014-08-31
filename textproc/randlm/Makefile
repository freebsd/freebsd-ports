# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	randlm
PORTVERSION=	0.2.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A toolkit for building randomized language models

BUILD_DEPENDS=	${LOCALBASE}/include/google/sparse_hash_map:${PORTSDIR}/devel/google-sparsehash
LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/include/google/sparse_hash_map:${PORTSDIR}/devel/google-sparsehash

GNU_CONFIGURE=	yes
USE_GCC=	yes
USE_PERL5=	run
USE_AUTOTOOLS=	libtoolize aclocal autoconf automake
AUTOMAKE_ARGS=	--add-missing
USE_LDCONFIG=	yes
USES=		libtool
MAKE_JOBS_UNSAFE=yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	cd ${WRKSRC}/hadoop && ${MV} strings.cpp strings.cc

.include <bsd.port.mk>
