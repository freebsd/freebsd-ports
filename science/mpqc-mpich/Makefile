# New ports collection makefile for:	mpqc-mpich
# Date created:			27 April 2001
# Whom:				Nakata Maho <chat95@mbox.kyoto-inet.or.jp>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../mpqc/

PKGNAMESUFFIX=	-mpich

.include "${MASTERDIR}/Makefile"

BUILD_DEPENDS+=	${LOCALBASE}/mpich/lib/libmpich.a:${PORTSDIR}/net/mpich

# MPICH implimentation is not thread safe
CONFIGURE_ARGS+=	--with-libdirs="-L${LOCALBASE}/lib -L${LOCALBASE}/mpich/lib" \
		--with-include="-I${LOCALBASE}/mpich/include -I${WRKDIR}" \
		--enable-always-use-mpi \
		--enable-threads=no
