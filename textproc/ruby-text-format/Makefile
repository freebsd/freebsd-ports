# New ports collection makefile for:	Text::Format for Ruby
# Date created:		24 October 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	text-format
PORTVERSION=	0.64
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.halostatue.ca/files/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Text::Format for Ruby

USE_RUBY=	yes

NO_BUILD=	yes

do-install:
	${CP} -R ${WRKSRC}/lib/* ${RUBY_SITELIBDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${CP} -R ${WRKSRC}/Changelog ${WRKSRC}/doc/* ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
