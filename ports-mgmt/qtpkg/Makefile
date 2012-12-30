# New ports collection makefile for:	qtpkg
# Date created:				Wed Jan 3 2001
# Whom:					Trenton Schulz <twschulz@cord.edu>
#
# $FreeBSD$
#

PORTNAME=	qtpkg
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	ports-mgmt
# mastersite disappeared around July 6 2003
MASTER_SITES=	# http://gauss.cord.edu/homepages/twschulz/demo/
DISTNAME=	qtpkg

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Qt based package removal tool
CFLAGS+=	${PTHREAD_CFLAGS}
MAKE_ENV=	LIBS="-lqt-mt ${PTHREAD_LIBS}"

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

PLIST_FILES=	sbin/qtpkg
USE_QT_VER=	3

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qtpkg ${PREFIX}/sbin

.include <bsd.port.mk>
