# New ports collection makefile for:	Ruby-sablot
# Date created:		9 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	sablot
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.rubycolor.org/arc/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	sablot.65:${PORTSDIR}/textproc/sablotron \
		iconv.2:${PORTSDIR}/converters/iconv \
		expat.2:${PORTSDIR}/textproc/expat2

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-sablot-lib="${LOCALBASE}" \
		--with-iconv="${LOCALBASE}" \
		--with-expat="${LOCALBASE}"
INSTALL_TARGET=	site-install

DOCS=		README		doc/*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
