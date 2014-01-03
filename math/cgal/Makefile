# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cgal
PORTVERSION=	4.1
CATEGORIES=	math
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/31640/:source1 \
		http://gforge.inria.fr/frs/download.php/31645/:source2 \
		http://gforge.inria.fr/frs/download.php/31644/:source3
DISTNAME=	CGAL-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source1 \
		${DISTNAME}-doc_html${EXTRACT_SUFX}:source2 \
		${PORTNAME}_manual.pdf:source3
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-doc_html${EXTRACT_SUFX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	A computational geometry library

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	GLU.1:${PORTSDIR}/graphics/libGLU \
		gmp.10:${PORTSDIR}/math/gmp \
		mpfr.4:${PORTSDIR}/math/mpfr

USE_BZIP2=		yes
USE_LDCONFIG=		yes
USES=			cmake
USE_QT4=		corelib opengl qmake_build gui moc_build rcc_build uic_build
HAS_CONFIGURE=		yes
DOCSDIR=		${PREFIX}/share/doc/CGAL-${PORTVERSION}
LDFLAGS+=		-L${LOCALBASE}/lib

MAN1=			cgal_create_cmake_script.1

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in AUTHORS CHANGES LICENSE LICENSE.FREE_USE LICENSE.GPL LICENSE.LGPL
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}_manual.pdf ${DOCSDIR}
.endif
	${INSTALL_MAN} ${WRKSRC}/auxiliary/cgal_create_cmake_script.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
