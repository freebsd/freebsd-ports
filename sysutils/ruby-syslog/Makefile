# New ports collection makefile for:	Ruby-syslog
# Date created:		15 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	syslog
PORTVERSION=	20010130
CATEGORIES=	sysutils ruby
MASTER_SITES=	http://www.utdallas.edu/~amos/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

post-extract:
	${RM} ${WRKSRC}/depend

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/syslog/
	${INSTALL_DATA} ${WRKSRC}/0README ${RUBY_DOCDIR}/syslog/
.endif

.include <bsd.port.mk>
