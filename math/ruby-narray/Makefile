# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	narray
PORTVERSION=	0.6.0.1
PORTREVISION=	3
CATEGORIES=	math ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Numerical N-dimensional array library for Ruby

LIB_DEPENDS=	libfftw.so:${PORTSDIR}/math/fftw

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install
MAKE_ARGS=	INSTALL_PROG="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}"

DOC_EN=		ChangeLog	README.en	SPEC.en
DOC_JA=		README.ja	SPEC.ja

OPTIONS_DEFINE=	DOCS

DEPRECATED=	RubyForge shutdown May 15 2014
EXPIRATION_DATE=	2014-09-20

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
.for f in ${DOC_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOC_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
.endfor

.include <bsd.port.mk>
