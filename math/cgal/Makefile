# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cgal
PORTVERSION=	4.3
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/32997/
DISTNAME=	CGAL-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Computational geometry library

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libGLU.so:${PORTSDIR}/graphics/libGLU \
		libgmp.so:${PORTSDIR}/math/gmp \
		libmpfr.so:${PORTSDIR}/math/mpfr

USE_LDCONFIG=		yes
USES=			cmake tar:bzip2
USE_QT4=		corelib opengl qmake_build gui moc_build rcc_build uic_build
HAS_CONFIGURE=		yes
LDFLAGS+=		-L${LOCALBASE}/lib

post-install:
	${INSTALL_MAN} ${WRKSRC}/auxiliary/cgal_create_cmake_script.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
