# New ports collection makefile for:	Ruby-syslog
# Date created:		15 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	syslog
PORTVERSION=	0.1.1
CATEGORIES=	sysutils ruby
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.bekkoame.ne.jp/~yoshidam/
MASTER_SITE_SUBDIR=	knu
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/syslog
	${INSTALL_DATA} ${WRKSRC}/test.rb ${RUBY_EXAMPLESDIR}/syslog/
	${MKDIR} ${RUBY_DOCDIR}/syslog/
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/syslog/
.endif

.include <bsd.port.mk>
