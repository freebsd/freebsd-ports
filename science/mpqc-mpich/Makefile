# New ports collection makefile for:	mpqc-mpich
# Date created:			27 April 2001
# Whom:				Nakata Maho <chat95@mbox.kyoto-inet.or.jp>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../mpqc/

.include "${.CURDIR}/../mpqc/Makefile"

PKGNAMESUFFIX=	-mpich

LIB_DEPENDS=	lapack:${PORTSDIR}/math/lapack \
		atlas:${PORTSDIR}/math/atlas
BUILD_DEPENDS=	${LOCALBASE}/mpich/lib/libmpich.a:${PORTSDIR}/net/mpich

# MPICH implimentation is not thread safe
CONFIGURE_ARGS+=	--with-libdirs="-L${PREFIX}/lib -L${PREFIX}/mpich/lib" \
		--with-include="-I${PREFIX}/mpich/include" \
		--enable-always-use-mpi \
		--enable-threads=no
