# New ports collection makefile for:	icemc
# Date created:				31 December 2001
# Whom:					Adam Weinberger <adam@vectors.cx>
#
# $FreeBSD$
#

PORTNAME=	icemc
PORTVERSION=	0.2.4
CATEGORIES=	misc
MASTER_SITES=	http://www.algorithm.at/comp/icemc/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	QT-based menu editor for IceWM

USE_X_PREFIX=	yes
USE_QT_VER=	3

MAKE_ARGS=     QTDIR="${X11BASE}" DESTDIR="${PREFIX}" \
               INCPATH="${QTCPPFLAGS} ${PTHREAD_CFLAGS}" \
               LFLAGS="${QTCFGLIBS} ${PTHREAD_LIBS}" \
               CC="${CC}" CXX="${CXX}" \
               CFLAGS="${CFLAGS} -DNO_DEBUG" \
               CXXFLAGS="${CXXFLAGS} -DNO_DEBUG" \
               LINK="${CXX}" LIBS="-lqt-mt" MOC="${MOC}"


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/icemc ${PREFIX}/bin

.include <bsd.port.mk>
