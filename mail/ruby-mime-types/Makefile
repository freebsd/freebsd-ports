# New ports collection makefile for:	MIME::Types for Ruby
# Date created:		24 October 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mime-types
PORTVERSION=	1.13
CATEGORIES=	mail ruby
MASTER_SITES=	http://www.halostatue.ca/files/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	MIME::Types for Ruby

USE_RUBY=	yes

NO_BUILD=	yes

DOCS=		ChangeLog Readme doc

do-install:
	${CP} -R ${WRKSRC}/lib/* ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
