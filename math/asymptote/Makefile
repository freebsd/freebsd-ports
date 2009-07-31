# New ports collection makefile for:	asymptote
# Date created:		2005-07-22
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	asymptote
PORTVERSION=	1.75
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}.src
EXTRACT_SUFX=	.tgz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A powerful script-based vector graphics language

.if defined(WITH_GSL)
LIB_DEPENDS+=	gsl.13:${PORTSDIR}/math/gsl
.endif
.if defined(WITH_FFTW)
LIB_DEPENDS=	fftw3.5:${PORTSDIR}/math/fftw3
.endif
BUILD_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick \
		dvips:${PORTSDIR}/print/dvipsk-tetex \
		latex:${PORTSDIR}/print/teTeX \
		makeinfo:${PORTSDIR}/textproc/texi2html \
		${MKTEXLSR}:${PORTSDIR}/print/teTeX \
		svn:${PORTSDIR}/devel/subversion \
		texi2dvi:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	gv:${PORTSDIR}/print/gv \
		latex:${PORTSDIR}/print/teTeX \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

ONLY_FOR_ARCHS=	i386 amd64
# it requires boehm-gc 7.X
CONFIGURE_ARGS=	--disable-gc

USE_GHOSTSCRIPT=yes
USE_GL=	glut
USE_GMAKE=	yes
USE_PYTHON=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-latex=${LOCALBASE}/share/texmf-local/tex/latex
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include $${CPPFLAGS}" LFLAGS="-L${LOCALBASE}/lib $${LFLAGS}" CFLAGS="-I${LOCALBASE}/include $${CFLAGS}" LDFLAGS="-L${LOCALBASE}/lib $${LDFLAGS}"
MAKE_ENV+=	${CONFIGURE_ENV}

MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
PLIST_SUB=	MKTEXLSR=${MKTEXLSR}

ALL_TARGET=	asy
INSTALL_TARGET=	install-asy

# Documentation
.if !defined(NOPORTDOCS)
MAN1=	asy.1 xasy.1x
INFO=	${PORTNAME} asy-faq

ALL_TARGET+=	doc
CONFIGURE_ARGS+=	--with-docdir=${DOCSDIR}
INSTALL_TARGET+=	install-doc
.endif
RM_OPTS=	-R

post-install:
# Examples
.if defined(NOPORTEXAMPLES)
	@${RM} ${RM_OPTS} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
