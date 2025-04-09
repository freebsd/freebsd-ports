PORTNAME=	hdf
DISTVERSION=	4.3.0
PORTEPOCH=	1
CATEGORIES=	science archivers graphics
MASTER_SITES=	https://github.com/HDFGroup/hdf4/releases/download/hdf${DISTVERSION}/
DISTNAME=	hdf${DISTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA)
WWW=		https://www.hdfgroup.org/solutions/hdf4/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=		aarch64 armv6 armv7
NOT_FOR_ARCHS_REASON=	fails to compile: no machine type has been defined

LIB_DEPENDS=	libsz.so:science/libaec

USES=		fortran jpeg libtool
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/hdfsrc

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared \
		--with-jpeg=${LOCALBASE} \
		--with-szlib=${LOCALBASE}

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=		JAVA
OPTIONS_DEFAULT=	JAVA
OPTIONS_SUB=		yes

JAVA_CONFIGURE_ENABLE=	java
JAVA_USES=		java:build
JAVA_VARS=		JAVA_VERSION=17
JAVA_CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME} \
			PATH=${JAVA_HOME}/bin:${PATH}
JAVA_MAKE_ENV=		PATH=${JAVA_HOME}/bin:${PATH}

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Type mismatch between actual argument at (1) and actual argument at (2) (CHARACTER(0)/INTEGER(4)).
# in theory, this should set FCFLAGS, but the port does not conform
FFLAGS+=	-fallow-argument-mismatch
.endif

CONFLICTS_INSTALL=	netcdf-4.[0-9]*

.include <bsd.port.post.mk>
