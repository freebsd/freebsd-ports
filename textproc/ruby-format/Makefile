# New ports collection makefile for:	FormatR
# Date created:		20 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	format
PORTVERSION=	1.03
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.crhc.uiuc.edu/~rubel/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	FormatR.${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

post-patch:
	${RUBY} -i.orig -pe 'gsub(/"(format_test\.pl)/, "\"./\\1")' ${WRKSRC}/test_format.rb

do-install:
	${INSTALL_DATA} ${WRKSRC}/format.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}/test
.for f in test_format.rb format_test.pl
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/${PORTNAME}/
.endfor
	${INSTALL_DATA} ${WRKSRC}/test/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/test/
.endif

.include <bsd.port.mk>
