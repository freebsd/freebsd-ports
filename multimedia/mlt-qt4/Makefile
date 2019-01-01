# $FreeBSD$

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

PORTREVISION=	1

CONFLICTS_INSTALL=	${PORTNAME}-qt5-*

USES=	qt:4
USE_QT=		corelib gui opengl svg xml
MASTERDIR=	${.CURDIR:H}/mlt
SLAVEPORT=	qt4

PLIST=		${MASTERDIR}-qt5/pkg-plist

USE_XORG=		x11

.include "${MASTERDIR}/Makefile"
