# New ports collection makefile for:	ruby-csv
# Date created:		18 Feb 2001
# Whom:			Yarema <yds@dppl.com>
#
# $FreeBSD$
#

PORTNAME=	csv
PORTVERSION=	1.0.0
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.jin.gr.jp/~nahi/Ruby/CSV/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

MODULES=	csv.rb

do-install:
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/lib/${f} ${RUBY_SITELIBDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/csv
	${INSTALL_DATA} ${WRKSRC}/README.txt ${RUBY_DOCDIR}/csv
.endif

.include <bsd.port.mk>
