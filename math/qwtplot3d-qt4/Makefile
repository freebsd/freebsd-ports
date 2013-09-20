# $FreeBSD$

PORTNAME=	qwtplot3d
PORTVERSION=	0.2.7
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	SF
PKGNAMESUFFIX=	-qt4
EXTRACT_SUFX=	.tgz

MAINTAINER=	makc@FreeBSD.org
COMMENT=	3D plotting widgets for scientific data and math expressions

USE_QT4=	gui moc_build qmake_build opengl
USE_GL=		glu
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
USE_DOS2UNIX=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
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
	${MKDIR} ${PREFIX}/include/qwtplot3d-qt4
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/qwtplot3d-qt4
	${MKDIR} ${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib/libqwtplot3d-qt4.so.${PORTVERSION} ${PREFIX}/lib
	${LN} -fs ${PREFIX}/lib/libqwtplot3d-qt4.so.${PORTVERSION} ${PREFIX}/lib/libqwtplot3d-qt4.so.0
	${LN} -fs ${PREFIX}/lib/libqwtplot3d-qt4.so.${PORTVERSION} ${PREFIX}/lib/libqwtplot3d-qt4.so

.include <bsd.port.mk>
