# New ports collection makefile for:	Ruby-sablot
# Date created:		9 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	sablot
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.rubycolor.org/arc/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	sablot.67:${PORTSDIR}/textproc/sablotron \
		iconv.2:${PORTSDIR}/converters/iconv \
		expat.2:${PORTSDIR}/textproc/expat2

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-sablot-lib="${LOCALBASE}" \
		--with-iconv="${LOCALBASE}" \
		--with-expat="${LOCALBASE}"
INSTALL_TARGET=	site-install

DOCS_EN=	README	\
		doc/sablot.html \
		doc/sablot.rd
DOCS_JA=	doc/sablot_ja.html \
		doc/sablot.rd.ja

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endfor
.endif

.include <bsd.port.mk>
