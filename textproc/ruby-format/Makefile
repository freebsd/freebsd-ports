# New ports collection makefile for:	FormatR
# Date created:		20 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	format
PORTVERSION=	0.93
CATEGORIES=	textproc ruby
#MASTER_SITES=	http://www.crhc.uiuc.edu/~rubel/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	FormatR-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
.if !defined(NOPORTDOCS)
USE_RUBY_RD=	yes
.endif

NO_WRKSUBDIR=	yes

do-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}; ${RUBY_RD} format.rb > format.html
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/format.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/test_format.rb ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/format.html ${RUBY_DOCDIR}/${PORTNAME}/
.endif

.include <bsd.port.mk>
