# New ports collection makefile for:	Ruby/MWDOM
# Date created:		22 August 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mwdom
PORTVERSION=	0.1.5
CATEGORIES=	textproc ruby
MASTER_SITES=	http://raa.ruby-lang.org/cache/mwdom/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	DOM level2 module, XMLWriter and XHTMLWriter for Ruby

RUN_DEPENDS=	${RUBY_SITELIBDIR}/xpathtree.rb:${PORTSDIR}/textproc/ruby-xmlscan-old

USE_BZIP2=	yes
USE_RUBY=	yes

NO_BUILD=	yes

do-install:
	${CP} -R ${WRKSRC}/mwdom ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.* ${RUBY_MODEXAMPLESDIR}/
.endif

.include <bsd.port.mk>
