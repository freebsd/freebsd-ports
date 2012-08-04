# New ports collection makefile for:	asymptote
# Date created:		2005-07-22
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	asymptote
PORTVERSION=	2.16
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src
EXTRACT_SUFX=	.tgz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A powerful script-based vector graphics language

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

RUN_DEPENDS=	gv:${PORTSDIR}/print/gv \
		latex:${PORTSDIR}/print/teTeX-base \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_PKGNAMEPREFIX}imaging>=1.1.6_3:${PORTSDIR}/graphics/py-imaging

ONLY_FOR_ARCHS=	i386 amd64
# it requires boehm-gc 7.X with Pthread enabled
CONFIGURE_ARGS=	--disable-gc

USE_GHOSTSCRIPT=yes
USE_GL=	glut
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
USE_PYTHON=	yes
MAKE_JOBS_UNSAFE=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-latex=${LOCALBASE}/share/texmf/tex/latex \
		--with-context=${LOCALBASE}/share/texmf/tex/context/third
CONFIGURE_ENV=	LFLAGS="-L${LOCALBASE}/lib $${LFLAGS}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	${CONFIGURE_ENV}

MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
PLIST_SUB=	MKTEXLSR=${MKTEXLSR}

ALL_TARGET=	asy asy-keywords.el
INSTALL_TARGET=	install-asy install-texhash

# Options
OPTIONS_DEFINE=	EXAMPLES GSL FFTW READLINE #DOCS MANPAGES
OPTIONS_DEFAULT=	EXAMPLES GSL FFTW READLINE #MANPAGES

GSL_DESC=	Enable GNU Scientific library
FFTW_DESC=	Use FFTW to compute the Discrete Fourier Transform
READLINE_DESC=	${LIBEDIT_DESC}

.include <bsd.port.options.mk>

# Documentation
#.if ${PORT_OPTIONS:MDOCS}
# teTeX is too old to compile the asymptote documentation
.if 0
ALL_TARGET+=	html
CONFIGURE_ARGS+=	--with-docdir=${DOCSDIR}
INSTALL_TARGET+=	install-html
.endif

#.if ${PORT_OPTIONS:MMANPAGES}
# teTeX is too old to compile the asymptote documentation
.if 0
MAN1=	asy.1 xasy.1x
INFO=	asy-faq
ALL_TARGET+=	man
INSTALL_TARGET+=	install-man
.endif

#.if ${PORT_OPTIONS:MMANPAGES} || ${PORT_OPTIONS:MDOCS}
# teTeX is too old to compile the asymptote documentation
.if 0
BUILD_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick \
		dvips:${PORTSDIR}/print/dvipsk-tetex \
		latex:${PORTSDIR}/print/teTeX-base \
		makeinfo:${PORTSDIR}/textproc/texi2html \
		${MKTEXLSR}:${PORTSDIR}/print/teTeX-base \
		svn:${PORTSDIR}/devel/subversion \
		texi2dvi:${PORTSDIR}/print/texinfo
.endif

# Examples
.if !${PORT_OPTIONS:MEXAMPLES}
post-install:
	@${RM} -R ${EXAMPLESDIR}
.endif

# Optimizations
.if ${PORT_OPTIONS:MGSL}
LIB_DEPENDS+=	gsl:${PORTSDIR}/math/gsl
CONFIGURE_ARGS+=	--enable-gsl
.else
CONFIGURE_ARGS+=	--disable-gsl
.endif

.if ${PORT_OPTIONS:MFFTW}
LIB_DEPENDS+=	fftw3:${PORTSDIR}/math/fftw3
CONFIGURE_ARGS+=	--enable-fftw
.else
CONFIGURE_ARGS+=	--disable-fftw
.endif

.if ${PORT_OPTIONS:MREADLINE}
CONFIGURE_ARGS+=	--enable-readline
.else
CONFIGURE_ARGS+=	--disable-readline
.endif

.include <bsd.port.mk>
