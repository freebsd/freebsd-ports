# $FreeBSD$

PORTNAME=	dlib
DISTVERSION=	19.13
CATEGORIES=	science devel math python
MASTER_SITES=	http://dlib.net/files/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	6yearold@gmail.com
COMMENT=	Machine learning framework written in C++ (python bindings)

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/dlib/LICENSE.txt

BUILD_DEPENDS=		cmake:devel/cmake
LIB_DEPENDS=		${PY_BOOST}

USES=			pkgconfig python shebangfix tar:bzip2
USE_PYTHON=		autoplist distutils
SHEBANG_FILES=		python_examples/*.py

OPTIONS_DEFINE=		X11 JPEG PNG GIF SQLITE BLASLAPACK AVX
OPTIONS_DEFAULT=	X11 JPEG PNG GIF SQLITE

BLASLAPACK_DESC=	Use Blas and Lapack libraries from ports
AVX_DESC=		Use AVX instructions if supported by CPU

X11_USE=		xorg=x11
X11_VARS_OFF=		x11args="--yes DLIB_NO_GUI_SUPPORT"

JPEG_USES=		jpeg
JPEG_VARS=		jpegargs="--yes DLIB_JPEG_SUPPORT"
JPEG_VARS_OFF=		jpegargs="--no DLIB_JPEG_SUPPORT"

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_VARS=		pngargs="--yes DLIB_PNG_SUPPORT"
PNG_VARS_OFF=		pngargs="--no DLIB_PNG_SUPPORT"

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_VARS=		gifargs="--yes DLIB_GIF_SUPPORT"
GIF_VARS_OFF=		gifargs="--no DLIB_GIF_SUPPORT"

SQLITE_USES=		sqlite
SQLITE_VARS=		sqliteargs="--yes DLIB_LINK_WITH_SQLITE3"
SQLITE_VARS_OFF=	sqliteargs="--no DLIB_LINK_WITH_SQLITE3"

BLASLAPACK_USES=	blaslapack
BLASLAPACK_VARS_OFF=	avxargs="--no DLIB_USE_BLAS --no DLIB_USE_LAPACK --no DLIB_USE_MKL_FFT"

AVX_VARS=		avxargs="--yes USE_AVX_INSTRUCTIONS"

PYDISTUTILS_BUILDARGS=	--set BOOST_PYTHON_SUFFIX:STRING=${PYTHON_SUFFIX} ${X11ARGS} ${JPEGARGS} ${PNGARGS} ${GIFARGS} ${SQLITEARGS} ${BLASLAPACKARGS} ${AVXARGS}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/dlib.so

.include <bsd.port.mk>
