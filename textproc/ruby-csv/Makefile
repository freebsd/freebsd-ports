# New ports collection makefile for:	ruby-csv
# Date created:		18 Feb 2001
# Whom:			Yarema <yds@dppl.com>
#
# $FreeBSD$
#

PORTNAME=	csv
PORTVERSION=	1.2.2
CATEGORIES=	textproc ruby
MASTER_SITES=	http://rrr.jin.gr.jp/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ruby library to parse or generate data in CSV format

DEPRECATED=	distfile and homepage disappeared
EXPIRATION_DATE=	2006-12-30

USE_RUBY=	yes

NO_BUILD=	yes

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${RUBY_MODDOCDIR}
.endif

.include <bsd.port.mk>
