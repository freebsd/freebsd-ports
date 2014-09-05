# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	gsl
PORTVERSION=	1.14.7
PORTREVISION=	2
CATEGORIES=	math ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	rb-${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	rb-${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Ruby extension library for GSL (GNU Scientific Library)

LIB_DEPENDS=	libgsl.so:${PORTSDIR}/math/gsl

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

CONFIGURE_ARGS=	-- --with-opt-dir="${LOCALBASE}"

DOCS=		AUTHORS ChangeLog THANKS rdoc

DEPRECATED=	RubyForge shutdown May 15 2014
EXPIRATION_DATE=	2014-09-20

OPTIONS_DEFINE=	DOCS

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
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${DOCS}" ${STAGEDIR}${RUBY_MODDOCDIR}/

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 2.0
BROKEN=		Does not build with Ruby 2.0 or newer
.endif

.include <bsd.port.post.mk>
