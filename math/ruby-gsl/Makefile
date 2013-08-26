# New ports collection makefile for:	Ruby/GSL
# Date created:		22 December 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gsl
PORTVERSION=	1.14.7
PORTREVISION=	1
CATEGORIES=	math ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	rb-${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	rb-${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A Ruby extension library for GSL (GNU Scientific Library)

LIB_DEPENDS=	gsl:${PORTSDIR}/math/gsl

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

CONFIGURE_ARGS=	-- --with-opt-dir="${LOCALBASE}"

DOCS=		AUTHORS ChangeLog THANKS rdoc

post-extract:
	${FIND} ${WRKSRC} '(' -name '.DS_Store' -o -name '*~' ')' -delete

post-patch:
	${REINPLACE_CMD} -e 's|gsl_matrix_complex_equal|rb_&|g' \
	${WRKSRC}/ext/matrix_complex.c
	${REINPLACE_CMD} -e 's|gsl_vector_complex_equal|rb_&|g' \
	${WRKSRC}/ext/vector_complex.c
	${REINPLACE_CMD} -Ee \
	'/(gsl_wavelet_direction|INT2FIX)/s/(for|back)ward/gsl_wavelet_&/' \
	${WRKSRC}/ext/wavelet.c
	${REINPLACE_CMD} -Ee '/INT2FIX/s/(for|back)ward/gsl_fft_&/' \
	${WRKSRC}/ext/fft.c

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${RUBY_MODEXAMPLESDIR}/
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${DOCS}" ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
