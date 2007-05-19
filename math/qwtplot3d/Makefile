# ex:ts=8
# Ports collection makefile for:	qwtplot3d
# Date created:			Aug 30, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qwtplot3d
PORTVERSION=	0.2.6
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	makc@issp.ac.ru
COMMENT=	A 3D plotting widget for scientific data and mathematical expressions

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3
USE_XLIB=	yes
USE_GL=		yes
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV=	QTDIR=${QT_PREFIX}
USE_LDCONFIG=	yes

pre-build:
	@cd ${WRKSRC}; qmake -spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ ${PORTNAME}.pro

do-install:
	${CP} ${WRKSRC}/include/* ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/libqwtplot3d.so.${PORTVERSION} ${PREFIX}/lib
	${LN} -fs ${PREFIX}/lib/libqwtplot3d.so.${PORTVERSION} ${PREFIX}/lib/libqwtplot3d.so.0
	${LN} -fs ${PREFIX}/lib/libqwtplot3d.so.${PORTVERSION} ${PREFIX}/lib/libqwtplot3d.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
