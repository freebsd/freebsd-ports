# New ports collection makefile for:	icemc
# Date created:				31 December 2001
# Whom:					Adam Weinberger <adam@vectors.cx>
#
# $FreeBSD$
#

PORTNAME=	icemc
PORTVERSION=	0.2.3
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.algorithm.at/comp/icemc/

MAINTAINER=	adamw@FreeBSD.org

USE_X_PREFIX=	yes
USE_QT_VER=	3

MAKE_ENV=	QTCPPFLAGS="${QTCPPFLAGS} ${PTHREAD_CFLAGS}" \
		QTCFGLIBS="${QTCFGLIBS} ${PTHREAD_LIBS}" MOC="${MOC}" LIBQT="-lqt-mt"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/icemc ${PREFIX}/bin

.include <bsd.port.mk>
