# New ports collection makefile for:	asymptote
# Date created:		2005-07-22
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	asymptote
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nivit@email.it
COMMENT=	A powerful script-based vector graphics language

LIB_DEPENDS=	fftw3.4:${PORTSDIR}/math/fftw3
BUILD_DEPENDS=	${NOEXISTENT}:${PORTSDIR}/devel/boehm-gc:fetch \
		convert:${PORTSDIR}/graphics/ImageMagick \
		latex:${PORTSDIR}/print/teTeX \
		makeinfo:${PORTSDIR}/textproc/texi2html \
		${MKTEXLSR}:${PORTSDIR}/print/teTeX \
		texi2dvi:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	ggv:${PORTSDIR}/print/ggv \
		latex:${PORTSDIR}/print/teTeX \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

# devel/boehm-gc
ONLY_FOR_ARCHS=	i386

USE_GCC=	3.3+
USE_GHOSTSCRIPT=yes
USE_GMAKE=	yes
USE_PYTHON=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gc=${GCVERSION} \
		--with-latex=${LOCALBASE}/share/texmf-local/tex/latex
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

ALL_TARGET+=	doc
INSTALL_TARGET+=	install-doc
.endif

LN_OPTS=	-sf

GCVERSION=	6.6
GC_DISTNAME=	gc${GCVERSION}.tar.gz

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
.endif

pre-configure:
	@cd ${WRKSRC}; \
	${LN} ${LN_OPTS} ${DISTDIR}/${GC_DISTNAME} ${GC_DISTNAME}

.include <bsd.port.post.mk>
