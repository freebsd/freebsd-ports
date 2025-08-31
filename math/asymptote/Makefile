PORTNAME=	asymptote
PORTVERSION=	2.92
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Powerful script-based vector graphics language
WWW=		https://asymptote.sourceforge.io/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libsigsegv.so:devel/libsigsegv
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cson>=0.8:devel/py-cson@${PY_FLAVOR} \
		${PY_PILLOW} \
		xdg-open:devel/xdg-utils

USES=		bison compiler:c++14-lang gettext-runtime ghostscript gl gmake gnome ncurses perl5 python \
		pyqt:5 shebangfix tar:tgz tex
SHEBANG_FILES=	GUI/*.py
USE_GL=		gl glu glut
USE_GNOME=	librsvg2:run
USE_PERL5=	build
USE_TEX=	dvipsk formats
USE_PYQT=	pyqt5:run

CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-lsp # disable the module with Boost-related errors

MAKE_ENV=	ASYMPTOTE_HOME=${WRKDIR} HOME=${WRKDIR}
MAKE_JOBS_UNSAFE=	yes # see https://github.com/vectorgraphics/asymptote/issues/331

ALL_TARGET=	asy asy-keywords.el
INSTALL_TARGET=	install-asy

SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFAULT=	FFTW GSL MANPAGES READLINE
OPTIONS_DEFINE=		BDWGC DOCS EXAMPLES FFTW GSL MANPAGES OFFSCREEN READLINE

BDWGC_LIB_DEPENDS=	libgc-threaded.so:devel/boehm-gc-threaded
BDWGC_DESC=		Enable Boehm-Demers-Weiser garbage collector
BDWGC_CONFIGURE_ENABLE=	gc=${LOCALBASE}

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
MANPAGES_INFO=	asy-faq

OFFSCREEN_CONFIGURE_ENABLE=	offscreen
OFFSCREEN_DESC=	Enable offscreen rendering using OSMesa library
OFFSCREEN_LIB_DEPENDS=	libOSMesa.so:graphics/libosmesa

READLINE_CONFIGURE_ENABLE=	readline
READLINE_USES=	readline

TEST_TARGET=	test
TEST_WRKSRC=	${WRKSRC}/tests

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
USES+=	llvm:max=15
.endif

post-patch:
	@${REINPLACE_CMD} 's/-lgc/-lgc-threaded/' ${WRKSRC}/configure
	@${REINPLACE_CMD} 's,makeinfo,${LOCALBASE}/bin/makeinfo,' \
		${WRKSRC}/doc/png/Makefile.in

# Fix the python interpreter in the generated file share/asymptote/GUI/xasyVersion.py:
	@${REINPLACE_CMD} 's,/usr/bin/env python3,${PYTHON_CMD},' ${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/asy

.include <bsd.port.mk>
