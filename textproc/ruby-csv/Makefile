# New ports collection makefile for:	ruby-csv
# Date created:		18 Feb 2001
# Whom:			Yarema <yds@dppl.com>
#
# $FreeBSD$
#

PORTNAME=	csv
PORTVERSION=	1.2.2
CATEGORIES=	textproc ruby
MASTER_SITES=	http://dev.ctor.org/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library to parse or generate data in CSV format

DEPRECATED=	Doesn't work with Ruby 1.9
EXPIRATION_DATE=	2011-08-03

USE_RUBY=	yes

NO_BUILD=	yes

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${RUBY_MODDOCDIR}
.endif

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif
.include <bsd.port.post.mk>
