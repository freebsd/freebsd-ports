# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PKGNAMESUFFIX=	-mpi

MAINTAINER=	jwbacon@tds.net

LIB_DEPENDS+=	mpi:${PORTSDIR}/net/openmpi

MASTERDIR=	${.CURDIR}/../fvcom

MAKE_ARGS+=	FC=${LOCALBASE}/mpi/openmpi/bin/mpif90 \
		PORT_CPP_FLAGS+=-DMULTIPROCESSOR

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
