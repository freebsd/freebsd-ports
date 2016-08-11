# Created by: Eric van Gyzen <vangyzen@stat.duke.edu>
# $FreeBSD$

PORTNAME=	libRmath

COMMENT=	The standalone math library from R

BROKEN=		fails to configure

DESCR=	${.CURDIR}/pkg-descr
LIBRMATH_SLAVEPORT=	yes
MASTERDIR=	${.CURDIR}/../R
PLIST=	${.CURDIR}/pkg-plist

BROKEN_powerpc64=	Does not build

.include "${MASTERDIR}/Makefile"
