# New ports collection makefile for:	Ruby-uri
# Date created:		14 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	uri
PORTVERSION=	4.27
CATEGORIES=	net ruby
MASTER_SITES=	http://www02.so-net.ne.jp/%7Egreentea/ruby/uri/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MODULES=	uri.rb urireg.rb

DOCS=		index.html
EXAMPLES=	in-uri.txt test-uri.rb

do-install:
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_SITELIBDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/uri
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/uri/
.endfor
	${MKDIR} ${RUBY_DOCDIR}/uri
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/uri/
.endfor
.endif

.include <bsd.port.mk>
