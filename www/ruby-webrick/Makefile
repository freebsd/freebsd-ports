# New ports collection makefile for:	WEBrick
# Date created:		7 February 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	webrick
PORTVERSION=	1.2.3
CATEGORIES=	www ruby
MASTER_SITES=	http://www.notwork.org/ipr/webrick/src/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

# optional dependencies
#RUN_DEPENDS=	${RUBY_SITELIBDIR}/erb/erb.rb:${PORTSDIR}/textproc/ruby-erb \
#		${RUBY_SITELIBDIR}/openssl.rb:${PORTSDIR}/security/ruby-openssl

USE_RUBY=	yes

NO_BUILD=	yes

DOCS=		ChangeLog README doc/*

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
