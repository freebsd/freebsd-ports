# New ports collection makefile for:	RubyMail
# Date created:		16 January 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mail
PORTVERSION=	0.6
CATEGORIES=	mail ruby
MASTER_SITES=	http://www.lickey.com/rubymail/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/bin/*.rb

DOCS=		NEWS README THANKS doc/*
EXAMPLES=	bin/*.rb dot.rdeliver

do-install:
	${MKDIR} ${RUBY_SITELIBDIR}/mail
	${CP} -R ${WRKSRC}/mail/* ${RUBY_SITELIBDIR}/mail/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
.for f in ${EXAMPLES}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/${PORTNAME}/
.endfor
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
	${CP} -R ${WRKSRC}/doc/* ${RUBY_DOCDIR}/${PORTNAME}/
.endif

.include <bsd.port.mk>
