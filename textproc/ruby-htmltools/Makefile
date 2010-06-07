# New ports collection makefile for:	ruby-htmltools
# Date created:		2005-03-31
# Whom:			Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	htmltools
PORTVERSION=	1.09
CATEGORIES=	textproc ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	ruby-${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tools for parsing and manipulating HTML text in Ruby

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb
CONFIGURE_ARGS=		--prefix=${PREFIX}
RUBY_INSTALL_ARGS=	--prefix=${PREFIX}
NOHARM_ARGS=	--no-harm
WRKSRC=		${WRKDIR}/ruby-${PORTNAME}

install-noharm:
	@${ECHO_MSG} "===>  Running ${RUBY_SETUP} to NOHARM-install (Just output, do nothing)"
	cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_SETUP} install ${NOHARM_ARGS} ${RUBY_INSTALL_ARGS}

do-install:
	@${ECHO_MSG} "===>  Running ${RUBY_SETUP} to install"
	@cd ${INSTALL_WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_SETUP} install ${RUBY_INSTALL_ARGS}

.include <bsd.port.mk>
