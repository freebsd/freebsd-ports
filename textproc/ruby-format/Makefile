# New ports collection makefile for:	FormatR
# Date created:		20 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	format
PORTVERSION=	1.02
CATEGORIES=	textproc ruby
#MASTER_SITES=	http://www.crhc.uiuc.edu/~rubel/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	FormatR-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

WRKSRC=		${WRKDIR}/FormatR
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/format.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
.for f in test_format.rb format_test.pl
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
