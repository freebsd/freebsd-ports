# New ports collection makefile for:	Ruby-syslog
# Date created:		15 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	syslog
PORTVERSION=	20011121b
CATEGORIES=	sysutils ruby
MASTER_SITES=	http://www.ruby-lang.org/~knu/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

DOCS=		ChangeLog syslog.txt

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/test.rb ${RUBY_EXAMPLESDIR}/${PORTNAME}/
.endif

.include <bsd.port.mk>
