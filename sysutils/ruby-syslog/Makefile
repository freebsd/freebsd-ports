# New ports collection makefile for:	Ruby-syslog
# Date created:		15 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	syslog
PORTVERSION=	0.1.1
CATEGORIES=	sysutils	# ruby
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.bekkoame.ne.jp/~yoshidam/
MASTER_SITE_SUBDIR=	knu
PKGNAMEPREFIX=	ruby-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_TARGET=	site-install
PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/syslog
	${INSTALL_DATA} ${WRKSRC}/test.rb ${PREFIX}/share/examples/ruby/syslog/
	${MKDIR} ${PREFIX}/share/doc/ruby/syslog/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ruby/syslog/
.endif

.include <bsd.port.mk>
