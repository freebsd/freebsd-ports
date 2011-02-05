# New ports collection makefile for:	hupnp
# Date created:				2010-12-29
# Whom:					Dima Panov <fluffy@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	hupnp
PORTVERSION=	0.7.0
CATEGORIES=	net devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}
DISTNAME=	herqq-${PORTVERSION}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	A library for building UPnP devices and control points

USE_ZIP=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib network xml dbus gui \
		qmake_build moc_build rcc_build uic_build
QMAKE_ARGS=	PREFIX=${PREFIX} herqq.pro

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS}

post-install:
	cd ${WRKSRC}/hupnp/include && ${COPYTREE_SHARE} \* ${PREFIX}/include
	cd ${WRKSRC}/hupnp/deploy/include && ${COPYTREE_SHARE} H\* ${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/hupnp/bin/libHUpnp.so.1.0.0 \
		${PREFIX}/lib/libHUpnp.so.1 && \
		${LN} -s ${PREFIX}/lib/libHUpnp.so.1 \
		${PREFIX}/lib/libHUpnp.so
	${INSTALL_LIB} ${WRKSRC}/hupnp/bin/libQtSolutions_SOAP-2.7.so.1.0.0 \
		${PREFIX}/lib/libQtSolutions_SOAP-2.7.so.1 && \
		${LN} -s ${PREFIX}/lib/libQtSolutions_SOAP-2.7.so.1 \
		${PREFIX}/lib/libQtSolutions_SOAP-2.7.so

.include <bsd.port.mk>
