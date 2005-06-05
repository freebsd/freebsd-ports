# New ports collection makefile for:	Ruby/fcgi
# Date created:		7 December 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	fcgi
PORTVERSION=	0.8.6
CATEGORIES=	www ruby
MASTER_SITES=	http://sugi.nemui.org/pub/ruby/fcgi/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	FastCGI library for Ruby

LIB_DEPENDS=	fcgi.0:${PORTSDIR}/www/fcgi

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb
CONFIGURE_ARGS=	-- --with-opt-dir="${LOCALBASE}"

DOCS=		README README.signals

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
