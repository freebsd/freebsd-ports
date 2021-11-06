PORTNAME=	smoldyn
DISTVERSION=	2.67
CATEGORIES=	science
MASTER_SITES=	https://www.smoldyn.org/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Biochemical simulator for molecular diffusion, surface interactions

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/License.txt

LIB_DEPENDS=	libtiff.so:graphics/tiff

USES=		cmake:testing compiler:c++11-lang gl tar:tgz xorg
USE_GL=		gl glu glut
USE_XORG=	xi xmu
USE_LDCONFIG=	yes

CMAKE_OFF=	OPTION_PYTHON
CMAKE_TESTING_ON=	OPTION_EXAMPLES # test code is missing from tarballs: https://github.com/ssandrews/Smoldyn/issues/111

PLIST_FILES=	bin/${PORTNAME} \
		include/libsmoldyn.h \
		include/smoldyn.h \
		include/smoldynconfigure.h \
		lib/libsmoldyn_shared.so \
		lib/libsmoldyn_static.a

.include <bsd.port.mk>
