PORTNAME=	asymptote
PORTVERSION=	3.12
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Powerful script-based vector graphics language
WWW=		https://asymptote.sourceforge.io/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	glm>0:math/glm \
		glslang>0:graphics/glslang \
		vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libglfw.so:graphics/glfw \
		libsigsegv.so:devel/libsigsegv \
		libvulkan.so:graphics/vulkan-loader \
		libglslang.so:graphics/glslang@shared
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cson>=0.8:devel/py-cson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside6>0:devel/pyside6 \
		${PY_PILLOW} \
		xdg-open:devel/xdg-utils

USES=		bison compiler:c++17-lang gettext-runtime ghostscript gl gmake \
		gnome ncurses perl5 python pyqt:6 shebangfix tar:tgz tex
SHEBANG_GLOB=	*.py
USE_GL=		gl glu
USE_GNOME=	librsvg2:run
USE_PERL5=	build
USE_TEX=	dvipsk formats
USE_PYQT=	pyqt6:run

BINARY_ALIAS=	python3=${PYTHON_VERSION}

CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-lsp # disable the module with Boost-related errors

MAKE_ENV=	ASYMPTOTE_HOME=${WRKDIR} HOME=${WRKDIR}
MAKE_JOBS_UNSAFE=yes # https://github.com/vectorgraphics/asymptote/issues/331 fixed but still needed

ALL_TARGET=	asy asy-keywords.el
INSTALL_TARGET=	install-asy

SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFAULT=	FFTW GSL MANPAGES READLINE
OPTIONS_DEFINE=		BDWGC DOCS EXAMPLES FFTW GSL MANPAGES READLINE

BDWGC_LIB_DEPENDS=	libgc-threaded.so:devel/boehm-gc-threaded
BDWGC_DESC=		Enable Boehm-Demers-Weiser garbage collector
BDWGC_CONFIGURE_ENABLE=	gc=${LOCALBASE}
BDWGC_BROKEN=		To be fixed

DOCS_ALL_TARGET=	html
DOCS_BUILD_DEPENDS=	texi2dvi:print/texinfo
DOCS_CONFIGURE_WITH=	docdir=${DOCSDIR}
DOCS_INSTALL_TARGET=	install-html

FFTW_CONFIGURE_ENABLE=	fftw
FFTW_DESC=	Use FFTW to compute the Discrete Fourier Transform
FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3

GSL_CONFIGURE_ENABLE=	gsl
GSL_DESC=	Enable GNU Scientific library
GSL_LIB_DEPENDS=	libgsl.so:math/gsl

MANPAGES_ALL_TARGET=	man
MANPAGES_BUILD_DEPENDS=	texi2dvi:print/texinfo
MANPAGES_INFO=		asy-faq

READLINE_CONFIGURE_ENABLE=	readline
READLINE_USES=	readline

TEST_TARGET=	test
TEST_WRKSRC=	${WRKSRC}/tests

PORTEXAMPLES=	*

pre-configure:
	${REINPLACE_CMD} 's/-lgc/-lgc-threaded/' ${WRKSRC}/configure
	${REINPLACE_CMD} 's,makeinfo,${LOCALBASE}/bin/makeinfo,' \
		${WRKSRC}/doc/png/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/asy

.include <bsd.port.mk>
