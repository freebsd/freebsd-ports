# New ports collection makefile for:	MIME::Types for Ruby
# Date created:		24 October 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mime-types
PORTVERSION=	1.003.1
CATEGORIES=	mail ruby
MASTER_SITES=	http://www.halostatue.ca/files/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	MIME-types-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

post-extract:
	cd ${WRKSRC}; ${MV} MIME/types.rb MIME/Types.rb

post-patch:
	${RUBY} -i -pe 'gsub %r"MIME/types\.rb", "MIME/Types.rb"' ${WRKSRC}/install.rb

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${CP} -R ${WRKSRC}/doc/* ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
