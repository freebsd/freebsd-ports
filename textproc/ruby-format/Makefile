# New ports collection makefile for:	FormatR
# Date created:		20 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	format
PORTVERSION=	1.09
CATEGORIES=	textproc ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}r
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	FormatR.${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Perl like formats for Ruby

USE_RUBY=	yes

NO_BUILD=	yes

post-patch:
	${RUBY} -i.orig -pe 'gsub(/"(format_test\.pl)/, "\"./\\1")' ${WRKSRC}/test_format.rb

do-install:
	${INSTALL_DATA} ${WRKSRC}/format.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/test
.for f in test_format.rb format_test.pl
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${INSTALL_DATA} ${WRKSRC}/test/* ${RUBY_MODEXAMPLESDIR}/test/
.endif

.include <bsd.port.mk>
