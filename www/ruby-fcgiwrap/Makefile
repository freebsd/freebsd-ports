# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

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

OPTIONS_DEFINE=	DOCS

RUN_DEPENDS=	${RUBY_SITELIBDIR}/fcgi.rb:${PORTSDIR}/www/ruby-fcgi

USE_RUBY=	yes

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/fcgiwrap.rb ${STAGEDIR}${RUBY_SITELIBDIR}/
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
	${INSTALL} ${WRKSRC}/ChangeLog ${WRKSRC}/README ${STAGEDIR}${RUBY_MODDOCDIR}/

.include <bsd.port.mk>
