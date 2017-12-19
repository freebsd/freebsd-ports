# Created by: Nakata Maho <chat95@mbox.kyoto-inet.or.jp>
# $FreeBSD$

PORTNAME=	pymol
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.6.0
CATEGORIES=	science biology python
MASTER_SITES=	SF/pymol/pymol/1.8/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenGL-based molecular visualization system

LICENSE=	PyMOL
LICENSE_NAME=	Open-Source PyMOL Copyright
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack-python>0:devel/py-msgpack-python@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Pmw>0:x11-toolkits/py-Pmw@${FLAVOR}
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng16.so:graphics/png \
		libmsgpackc.so:devel/msgpack

WRKSRC=		${WRKDIR}/pymol

USES=		compiler:c++11-lang python shebangfix tar:bz2
USE_GL=		gl glew glu glut
USE_GNOME=	libxml2
USE_PYTHON=	distutils concurrent  # autoplist is broken: https://sourceforge.net/p/pymol/bugs/189
SHEBANG_FILES=	test/show test/run test/cyg

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pymol/_cmd.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/chempy/champ/_champ.so

.include <bsd.port.mk>
