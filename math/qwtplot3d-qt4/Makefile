# New ports collection makefile for:	qwtplot3d-qt4
# Date created:		2007-05-27
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	qwtplot3d
PORTVERSION=	0.2.7
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF
PKGNAMESUFFIX=	-qt4
EXTRACT_SUFX=	.tgz

MAINTAINER=	makc@issp.ac.ru
COMMENT=	3D plotting widgets for scientific data and math expressions

USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build qmake_build opengl
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
USE_DOS2UNIX=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${QMAKE} -unix ${PORTNAME}.pro

pre-build:
	cd ${WRKSRC} && ${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; \
		 s|^CXX .*|CXX=${CXX}|; \
		 s|^LINK .*|LINK=${CXX}|; \
		 s|^\(INCPATH .*=\)|\1 -Iinclude|;'  Makefile
do-install:
	(cd ${WRKSRC}/include/ && ${COPYTREE_SHARE} \* ${PREFIX}/include/qwtplot3d-qt4)
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libqwtplot3d-qt4.so.${PORTVERSION} ${PREFIX}/lib
	${LN} -fs ${PREFIX}/lib/libqwtplot3d-qt4.so.${PORTVERSION} ${PREFIX}/lib/libqwtplot3d-qt4.so.0
	${LN} -fs ${PREFIX}/lib/libqwtplot3d-qt4.so.${PORTVERSION} ${PREFIX}/lib/libqwtplot3d-qt4.so

.include <bsd.port.mk>
