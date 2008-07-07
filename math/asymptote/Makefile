# New ports collection makefile for:	asymptote
# Date created:		2005-07-22
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	asymptote
PORTVERSION=	1.43
#PORTREVISION=	0
CATEGORIES=	math
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}.src
EXTRACT_SUFX=	.tgz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A powerful script-based vector graphics language

LIB_DEPENDS=	fftw3.4:${PORTSDIR}/math/fftw3
BUILD_DEPENDS=	boehm-gc>=6.8:${PORTSDIR}/devel/boehm-gc \
		convert:${PORTSDIR}/graphics/ImageMagick \
		dvips:${PORTSDIR}/print/dvipsk-tetex \
		latex:${PORTSDIR}/print/teTeX \
		makeinfo:${PORTSDIR}/textproc/texi2html \
		${MKTEXLSR}:${PORTSDIR}/print/teTeX \
		texi2dvi:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	boehm-gc>=6.8:${PORTSDIR}/devel/boehm-gc \
		gv:${PORTSDIR}/print/gv \
		latex:${PORTSDIR}/print/teTeX \
		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

# devel/boehm-gc
ONLY_FOR_ARCHS=	i386 amd64

USE_GCC=	3.3+
USE_GHOSTSCRIPT=yes
USE_GMAKE=	yes
USE_PYTHON=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gc=system --with-latex=${LOCALBASE}/share/texmf-local/tex/latex
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include $${CPPFLAGS}" LFLAGS="-L${LOCALBASE}/lib $${LFLAGS}" CFLAGS="-I${LOCALBASE}/include $${CFLAGS}" LDFLAGS="-L${LOCALBASE}/lib $${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ENV+=	${CONFIGURE_ENV}

MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
PLIST_SUB=	MKTEXLSR=${MKTEXLSR}

ALL_TARGET=	asy
INSTALL_TARGET=	install-asy

.if defined(WITH_GSL)
LIB_DEPENDS+=	gsl.12:${PORTSDIR}/math/gsl
.endif

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
