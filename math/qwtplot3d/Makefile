# ex:ts=8
# Ports collection makefile for:	qwtplot3d
# Date created:			Aug 30, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	qwtplot3d
PORTVERSION=	0.2.4.b
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/-beta/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 3D plotting widget for scientific data and mathematical expressions

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=     3
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV=       QTDIR=${X11BASE} \
		MOC=${MOC}
INSTALLS_SHLIB=	yes

pre-build:
	@cd ${WRKSRC}; qmake -spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ ${PORTNAME}.pro

do-install:
	${CP} ${WRKSRC}/include/* ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/libqwtplot3d.so.0.2.4 ${PREFIX}/lib
	${LN} -fs ${PREFIX}/lib/libqwtplot3d.so.0.2.4 ${PREFIX}/lib/libqwtplot3d.so.0
	${LN} -fs ${PREFIX}/lib/libqwtplot3d.so.0.2.4 ${PREFIX}/lib/libqwtplot3d.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
