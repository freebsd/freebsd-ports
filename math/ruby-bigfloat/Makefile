# New ports collection makefile for:	Ruby-BigFloat
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	bigfloat
PORTVERSION=	1.1.6
CATEGORIES=	math ruby
MASTER_SITES=	http://www.tinyforest.gr.jp/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}.html ${PORTNAME}_en.html
DIST_SUBDIR=	ruby
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

NO_WRKSUBDIR=	yes
INSTALL_TARGET=	site-install

DOCS_EN=	README ${PORTNAME}_en.html
DOCS_JA=	${PORTNAME}.html

post-extract:
	${RUBY} -pe 'gsub %r|\./(${PORTNAME}_en.html)|, "../\\1"' \
		${_DISTDIR}/${PORTNAME}.html > ${WRKSRC}/${PORTNAME}.html
	${RUBY} -pe 'gsub %r|\./(${PORTNAME}.html)|, "./ja/\\1"' \
		${_DISTDIR}/${PORTNAME}_en.html > ${WRKSRC}/${PORTNAME}_en.html

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endfor
.endif

.include <bsd.port.mk>
