# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cgal
PORTVERSION=	3.6.1
CATEGORIES=	math
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/27222/:source1 \
		http://gforge.inria.fr/frs/download.php/27226/:source2 \
		http://gforge.inria.fr/frs/download.php/27227/:source3
DISTNAME=	CGAL-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source1 \
		${DISTNAME}-doc_html${EXTRACT_SUFX}:source2 \
		${PORTNAME}_manual.pdf:source3
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-doc_html${EXTRACT_SUFX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	A computational geometry library

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05
BROKEN=		does not build with boost-1.48.0

BUILD_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	GLU.1:${PORTSDIR}/graphics/libGLU \
		gmp.10:${PORTSDIR}/math/gmp \
		mpfr.4:${PORTSDIR}/math/mpfr

FETCH_ARGS=	-pRr

USE_LDCONFIG=		yes
USE_CMAKE=		yes
USE_QT4=		corelib opengl qmake_build gui moc_build rcc_build
HAS_CONFIGURE=		yes
DOCSDIR=		${PREFIX}/share/doc/CGAL-3.4
LDFLAGS+=		-L${LOCALBASE}/lib

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
