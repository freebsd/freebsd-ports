# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTREVISION=	3
PKGNAMESUFFIX=	-mpi

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS+=	libmpi.so:${PORTSDIR}/net/openmpi

MASTERDIR=	${.CURDIR}/../fvcom

MAKE_ARGS+=	FC=${LOCALBASE}/mpi/openmpi/bin/mpif90 \
		PORT_CPP_FLAGS+=-DMULTIPROCESSOR

.include "${MASTERDIR}/Makefile"
