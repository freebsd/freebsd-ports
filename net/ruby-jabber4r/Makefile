# New ports collection makefile for:	jabber4r
# Date created:		11 December 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	jabber4r
PORTVERSION=	0.3.0
CATEGORIES=	net ruby
MASTER_SITES=	http://www.infoether.com/ruby/jabber4r/releases/
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/rexml/rexml.rb:${PORTSDIR}/textproc/ruby-rexml

USE_ZIP=	yes

USE_RUBY=	yes

NO_BUILD=	yes

DOCS=		LICENSE.txt README doc
EXAMPLES=	examples/*

post-extract:
	${RM} ${WRKSRC}/lib/jabber4r/LICENSE.txt

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.mk>
