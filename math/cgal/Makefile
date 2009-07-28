# New ports collection makefile for:	cgal
# Date created:				10 Apr 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cgal
PORTVERSION=	3.4
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/15692/
DISTNAME=	CGAL-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-doc_html${EXTRACT_SUFX} \
		${PORTNAME}_manual.pdf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-doc_html${EXTRACT_SUFX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	A computational geometry library

BUILD_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	GLU.1:${PORTSDIR}/graphics/libGLU \
		gmp.8:${PORTSDIR}/math/libgmp4 \
		mpfr.3:${PORTSDIR}/math/mpfr

USE_LDCONFIG=		yes
USE_CMAKE=		yes
USE_QT_VER=		4
CMAKE_USE_PTHREAD=	yes
QT_COMPONENTS=		corelib opengl qmake_build gui moc_build rcc_build
HAS_CONFIGURE=		yes
DOCSDIR=		${PREFIX}/share/doc/CGAL-3.4
CONFIGURE_ENV+=		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=			cgal_create_cmake_script.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in AUTHORS CHANGES LICENSE LICENSE.FREE_USE LICENSE.LGPL LICENSE.QPL
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}_manual.pdf ${DOCSDIR}
.endif
	${INSTALL_MAN} ${WRKSRC}/auxiliary/cgal_create_cmake_script.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
