# $FreeBSD$

PORTREVISION=	0

CONFLICTS_INSTALL=	${PORTNAME}-qt4-*

USE_CXXSTD=	c++11
USE_QT5=	core gui svg widgets xml
USE_XORG=	x11
MASTERDIR=	${.CURDIR:H}/mlt
SLAVEPORT=	qt5

.include "${MASTERDIR}/Makefile"
