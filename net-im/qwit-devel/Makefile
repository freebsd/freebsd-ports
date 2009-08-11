# New ports collection makefile for:	qwit
# Date created:		Sun March 1 19:29:11 MSD 2009
# Whom:			Sokolov Alexey <sokolov@TrueBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qwit
DISTVERSION=	r215
CATEGORIES=	net-im
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	qwit-ng-${PORTVERSION}-src
PKGNAMESUFFIX=	-devel

MAINTAINER=	sokolov@TrueBSD.org
COMMENT=	A Qt4-based lightweight Twitter client

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui network xml qmake_build moc_build rcc_build \
		uic

PLIST_FILES=	bin/qwit-devel

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -o Makefile qwit2.pro

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/qwit2 ${PREFIX}/bin/qwit-devel

.include <bsd.port.mk>
