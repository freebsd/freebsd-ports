# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	asymptote
PORTVERSION=	2.37
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Powerful script-based vector graphics language

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	libgc-threaded.so:devel/boehm-gc-threaded \
		libsigsegv.so:devel/libsigsegv
RUN_DEPENDS=	animate:graphics/ImageMagick \
		gv:print/gv \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter

ALL_TARGET=	asy asy-keywords.el

CONFIGURE_ARGS=	--enable-gc=system
CPPFLAGS+=	-I${LOCALBASE}/include

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-asy

MAKE_ENV=	ASYMPTOTE_HOME=${WRKDIR} HOME=${WRKDIR}
MAKE_JOBS_UNSAFE=	yes

ONLY_FOR_ARCHS=	i386 amd64

USES=		gettext-runtime ghostscript gmake ncurses perl5 python tar:tgz
USE_GL=	glut
USE_PERL5=	build
USE_TEX=	dvipsk formats

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

# Options
DOCS_BUILD_DEPENDS=	texi2dvi:print/texinfo
DOCS_CONFIGURE_WITH=	docdir=${DOCSDIR}

FFTW_CONFIGURE_ENABLE=	fftw
FFTW_DESC=	Use FFTW to compute the Discrete Fourier Transform
FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3

GSL_CONFIGURE_ENABLE=	gsl
GSL_DESC=	Enable GNU Scientific library
GSL_LIB_DEPENDS=	libgsl.so:math/gsl

MANPAGES_BUILD_DEPENDS=	texi2dvi:print/texinfo

OFFSCREEN_CONFIGURE_ENABLE=	offscreen
OFFSCREEN_DESC=	Enable offscreen rendering using OSMesa library
OFFSCREEN_LIB_DEPENDS=	libOSMesa.so:graphics/libosmesa
OPTIONS_DEFAULT=	FFTW GSL MANPAGES READLINE
OPTIONS_DEFINE=	DOCS EXAMPLES FFTW GSL MANPAGES OFFSCREEN READLINE

READLINE_CONFIGURE_ENABLE=	readline
READLINE_DESC=	${LIBEDIT_DESC}
READLINE_USES=	readline

.include <bsd.port.options.mk>

# Documentation
.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	html
INSTALL_TARGET+=	install-html
.endif

.if ${PORT_OPTIONS:MMANPAGES}
INFO=	asy-faq
ALL_TARGET+=	man
INSTALL_TARGET+=	install-man
.endif

post-patch:
	@${REINPLACE_CMD} 's/-lgc/-lgc-threaded/' ${WRKSRC}/configure
	@${REINPLACE_CMD} 's,/usr/lib/libgs.so,${LOCALBASE}/lib/libgs.so,' \
		${WRKSRC}/settings.cc

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/asy

.include <bsd.port.mk>
