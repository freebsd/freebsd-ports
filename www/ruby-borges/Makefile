# New ports collection makefile for:	Ruby-Borges
# Date created:		31 January 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	borges
PORTVERSION=	0.1.0
CATEGORIES=	www ruby
MASTER_SITES=	http://segment7.net/ruby-code/borges/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/webrick.rb:${PORTSDIR}/www/ruby-webrick

USE_RUBY=	yes

NO_BUILD=	yes

DOCS=		CHANGELOG README TODO
EXAMPLES=	data/examples/ruby/borges/*

do-install:
	${CP} -R ${WRKSRC}/lib/* ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
