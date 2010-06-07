# New ports collection makefile for:	Ruby/fcgiwrap
# Date created:		31 March 2007
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	fcgiwrap
PORTVERSION=	0.1.6
CATEGORIES=	www ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	fcgi
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Handy FastCGI wrapper library for CGI scripts written in Ruby

RUN_DEPENDS=	${RUBY_SITELIBDIR}/fcgi.rb:${PORTSDIR}/www/ruby-fcgi

USE_RUBY=	yes

NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/fcgiwrap.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL} ${WRKSRC}/ChangeLog ${WRKSRC}/README ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
