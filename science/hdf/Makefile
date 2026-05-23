PORTNAME=	hdf
PORTVERSION=	4.3.1
PORTEPOCH=	1
CATEGORIES=	science archivers graphics
MASTER_SITES=	https://github.com/HDFGroup/hdf4/releases/download/hdf${PORTVERSION}/
DISTNAME=	hdf${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA)
WWW=		https://www.hdfgroup.org/solutions/hdf4/ \
		https://github.com/HDFGroup/hdf4

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=	aarch64 armv6 armv7
NOT_FOR_ARCHS_REASON=	fails to compile: no machine type has been defined

LIB_DEPENDS=	libsz.so:science/libaec

USES=		fortran jpeg libtool

FFLAGS+=	-fallow-argument-mismatch
CONFIGURE_ARGS=	--enable-shared \
		--with-jpeg=${LOCALBASE} \
		--with-szlib=${LOCALBASE}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/hdf-${PORTVERSION}

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CONFLICTS_INSTALL=	netcdf-4.[0-9]*

OPTIONS_DEFINE=	JAVA
OPTIONS_DEFAULT=JAVA
OPTIONS_SUB=	yes

JAVA_CONFIGURE_ENABLE=	java
JAVA_CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME} \
			PATH=${JAVA_HOME}/bin:${PATH}
JAVA_MAKE_ENV=		PATH=${JAVA_HOME}/bin:${PATH}
JAVA_USES=		java:build

.include <bsd.port.mk>
