PORTNAME=	precice
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
CATEGORIES=	science # physics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Coupling library for partitioned multi-physics simulations

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libmpicxx.so:net/mpich \
		libpetsc.so:science/PETSc

USES=		cmake:noninja,testing compiler:c++14-lang eigen:3 gnome pkgconfig # fails with ninja: phony target 'binprecice' names itself as an input; ignoring
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes

CMAKE_OFF=	BUILD_TESTING PRECICE_ENABLE_FORTRAN PRECICE_PythonActions

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

# several tests are known to fail, see https://github.com/precice/precice/issues/1331

post-install: # remove files which aren't docs
	@${RM} -r ${STAGEDIR}${PREFIX}/share/doc

.include <bsd.port.mk>
