# New ports collection makefile for:	Ruby/http-access
# Date created:		31 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	http-access
PORTVERSION=	2.0.9
CATEGORIES=	www ruby
MASTER_SITES=	http://dev.ctor.org/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby library to access the Internet via HTTP

USE_RUBY=	yes

NO_BUILD=	yes

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
	${INSTALL_DATA} ${WRKSRC}/lib/http-access2/cacert.p7s ${RUBY_SITELIBDIR}/http-access2/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
