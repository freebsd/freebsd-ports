# New ports collection makefile for:	asymptote
# Date created:		2005-07-22
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	asymptote
PORTVERSION=	0.83
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nivit@email.it
COMMENT=	A powerful script-based vector graphics language

LIB_DEPENDS=	gc.1:${PORTSDIR}/devel/boehm-gc \
		fftw3.3:${PORTSDIR}/math/fftw3
# requires devel/boehm-gc distfile
BUILD_DEPENDS=	${DISTDIR}/${GC_DISTNAME}:${PORTSDIR}/devel/boehm-gc:fetch \
		convert:${PORTSDIR}/graphics/ImageMagick \
		latex:${PORTSDIR}/print/teTeX \
		makeinfo:${PORTSDIR}/textproc/texi2html \
		${MKTEXLSR}:${PORTSDIR}/print/teTeX \
		texi2dvi:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

# boehm-gc
ONLY_FOR_ARCHS=	i386

USE_GHOSTSCRIPT=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-latex=${LOCALBASE}/share/texmf-local/tex/latex
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include $${CPPFLAGS}" LFLAGS="-L${LOCALBASE}/lib $${LFLAGS}" CFLAGS="-I${LOCALBASE}/include $${CFLAGS}" LDFLAGS="-L${LOCALBASE}/lib $${LDFLAGS}"
MAKE_ENV+=	${CONFIGURE_ENV}

MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
PLIST_SUB=	MKTEXLSR=${MKTEXLSR}

ALL_TARGET=	asy
INSTALL_TARGET=	install-asy

# Documentation
.if !defined(NOPORTDOCS)
MAN1=	asy.1 xasy.1x
INFO=	${PORTNAME}

ALL_TARGET+=	man
INSTALL_TARGET+=	install-man
.endif

LN_OPTS=	-sf

GCVERSION=	6.5	# hardcoded in asymptote configure
GC_DISTNAME=	gc${GCVERSION}.tar.gz

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
# require exact version of gcc on 4.X
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
USE_GCC=	3.3
.else
USE_GCC=	3.3+
.endif

pre-configure:
	@cd ${WRKSRC}; \
	${LN} ${LN_OPTS} ${DISTDIR}/${GC_DISTNAME} ${GC_DISTNAME}

.include <bsd.port.post.mk>
