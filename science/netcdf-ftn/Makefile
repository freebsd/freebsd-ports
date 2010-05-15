# New ports collection makefile for:	netcdf-ftn
# Date created:		Sun Mar 08 2009
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	netcdf

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	NetCDF (network Common Data Form), with Fortran support

NETCDF_VER?=	4

.if ${NETCDF_VER} == 4
MASTERDIR=	${.CURDIR}/../netcdf4
.else
MASTERDIR=	${.CURDIR}/../netcdf
.endif

WITH_FORTRAN=	yes

.include "${MASTERDIR}/Makefile"
