PORTNAME=	hdf
PORTVERSION=	4.2.15
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	science archivers graphics
MASTER_SITES=	http://www.hdfgroup.org/ftp/HDF/releases/HDF${PORTVERSION}/src/ \
		ftp://ftp.hdfgroup.org/HDF/releases/HDF${PORTVERSION}/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA)
WWW=		https://www.hdfgroup.org/products/hdf4/

NOT_FOR_ARCHS=		aarch64 armv6 armv7
NOT_FOR_ARCHS_REASON=	fails to compile: no machine type has been defined

LIB_DEPENDS=	libsz.so:science/libaec

CONFLICTS_INSTALL=	netcdf-4.[0-9]*

USES=		fortran jpeg libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --with-jpeg=${LOCALBASE} \
		--with-szlib=${LOCALBASE}
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share/
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PORTDATA=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Type mismatch between actual argument at (1) and actual argument at (2) (CHARACTER(0)/INTEGER(4)).
# in theory, this should set FCFLAGS, but the port does not conform
FFLAGS+=	-fallow-argument-mismatch
.endif

post-patch:
	@${REINPLACE_CMD} -e '/PROD_/ s|=.*|=""|' ${WRKSRC}/config/freebsd
	@${REINPLACE_CMD} -e 's/ || (__APPLE__.*//' \
		${WRKSRC}/hdf/test/fortest.c

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/hdfunpac.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	# Allow to build on PowerPC
	@${REINPLACE_CMD} -e '/if defined (__APPLE__)/ \
		s,),) || defined(__powerpc__),' ${WRKSRC}/hdf/src/hdfi.h
	${INSTALL_MAN} ${WRKSRC}/man/gr_chunk.3 \
		${STAGEDIR}${PREFIX}/share/man/man3

.include <bsd.port.post.mk>
