# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	asymptote
PORTVERSION=	2.32
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Powerful script-based vector graphics language

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	libgc-threaded.so:${PORTSDIR}/devel/boehm-gc-threaded
RUN_DEPENDS=	animate:${PORTSDIR}/graphics/ImageMagick \
		gv:${PORTSDIR}/print/gv \
		${PYTHON_PKGNAMEPREFIX}imaging>=1.1.6_3:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter

ALL_TARGET=	asy asy-keywords.el

CONFIGURE_ARGS=	--enable-gc
CPPFLAGS+=	-I${LOCALBASE}/include

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-asy

MAKE_ENV=	${CONFIGURE_ENV} ASYMPTOTE_HOME=${WRKDIR} HOME=${WRKDIR}
MAKE_JOBS_UNSAFE=	yes

ONLY_FOR_ARCHS=	i386 amd64

USES=		gmake perl5 tar:tgz
USE_AUTOTOOLS=	autoconf aclocal
USE_GHOSTSCRIPT=yes
USE_GL=	glut
USE_PERL5=	build
USE_PYTHON=	yes
USE_TEX=	dvipsk formats texlive

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

# Options
DOCS_BUILD_DEPENDS=	texi2dvi:${PORTSDIR}/print/texinfo
DOCS_CONFIGURE_WITH=	docdir=${DOCSDIR}

FFTW_CONFIGURE_ENABLE=	fftw
FFTW_DESC=	Use FFTW to compute the Discrete Fourier Transform
FFTW_LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3

GSL_CONFIGURE_ENABLE=	gsl
GSL_DESC=	Enable GNU Scientific library
GSL_LIB_DEPENDS=	libgsl.so:${PORTSDIR}/math/gsl

MANPAGES_BUILD_DEPENDS=	texi2dvi:${PORTSDIR}/print/texinfo

OFFSCREEN_CONFIGURE_ENABLE=	offscreen
OFFSCREEN_DESC=	Enable offscreen rendering using OSMesa library
OFFSCREEN_LIB_DEPENDS=	libOSMesa.so:${PORTSDIR}/graphics/libosmesa
OPTIONS_DEFAULT=	FFTW GSL MANPAGES READLINE
OPTIONS_DEFINE=	DOCS EXAMPLES FFTW GSL MANPAGES OFFSCREEN READLINE

READLINE_CONFIGURE_ENABLE=	readline
READLINE_DESC=	${LIBEDIT_DESC}

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
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},1' -i.bak ${WRKSRC}/settings.cc

run-autotools:
	@(cd ${CONFIGURE_WRKSRC} && \
	${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} --force --install)

post-install:
	@(cd ${STAGEDIR}${PREFIX}/bin && \
	${LN} -sf ../share/asymptote/GUI/xasy.py xasy)
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/asy

.include <bsd.port.mk>
