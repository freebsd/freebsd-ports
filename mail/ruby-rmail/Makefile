# New ports collection makefile for:	RubyMail
# Date created:		16 January 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rmail
PORTVERSION=	0.9
CATEGORIES=	mail ruby
MASTER_SITES=	http://www.lickey.com/rubymail/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	rubymail-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

DOCS=		NEWS README THANKS doc

post-extract:
	${FIND} ${WRKSRC} -name '*~' -delete

do-install:
	${MKDIR} ${RUBY_SITELIBDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/${PORTNAME}/* ${RUBY_SITELIBDIR}/${PORTNAME}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
