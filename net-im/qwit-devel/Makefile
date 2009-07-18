# New ports collection makefile for:	qwit
# Date created:		Sun March 1 19:29:11 MSD 2009
# Whom:			Sokolov Alexey <sokolov@TrueBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qwit
DISTVERSION=	r154
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	qwit-${PORTVERSION}-src

MAINTAINER=	sokolov@TrueBSD.org
COMMENT=	A Qt4-based lightweight Twitter client

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui network xml qmake_build moc_build rcc_build \
		uic

PLIST_FILES=	bin/qwit

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -o Makefile qwit.pro

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/qwit ${PREFIX}/bin

.include <bsd.port.mk>
