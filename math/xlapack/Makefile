PORTNAME=	xlapack

MAINTAINER=	fortran@FreeBSD.org
COMMENT=	Extended Precision LAPACK

BROKEN=	3.12.1 does not build, see https://github.com/Reference-LAPACK/lapack/issues/1092

XLAPACK_SLAVEPORT=	yes

MASTERDIR=	${.CURDIR}/../lapack

.include "${MASTERDIR}/Makefile"
