# New ports collection makefile for:	Ruby-DRb
# Date created:		9 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	drb
PORTVERSION=	1.3.1
CATEGORIES=	net ruby
MASTER_SITES=	${MASTER_SITE_RUBY} \
		http://www2a.biglobe.ne.jp/~seki/ruby/
MASTER_SITE_SUBDIR=	contrib
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

# not mandatory, but recommended to use acl with DRb
RUN_DEPENDS=	${RUBY_SITELIBDIR}/acl.rb:${PORTSDIR}/security/ruby-acl

USE_RUBY=	yes

NO_BUILD=	yes

post-extract:
	${RM} ${WRKSRC}/lib/acl.rb

do-install:
	@cd ${WRKSRC}; \
	${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/drb
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/drb
.endif

.include <bsd.port.mk>
