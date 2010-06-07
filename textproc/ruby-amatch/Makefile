# New ports collection makefile for:	Ruby/amatch
# Date created:		10 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	amatch
PORTVERSION=	0.2.5
CATEGORIES=	textproc ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby library for approximate string matching and searching

USE_RUBY=	yes
USE_GMAKE=	yes
NO_BUILD=	yes # build while install

PLIST_FILES=	bin/agrep.rb %%RUBY_SITELIBDIR%%/amatch/version.rb \
		%%RUBY_SITEARCHLIBDIR%%/amatch.so
PLIST_DIRS=	%%RUBY_SITELIBDIR%%/amatch

AMATCH_RUBY=	install.rb
DOCSDIR=	${RUBY_MODDOCDIR}
PORTDOCS=	CHANGES README

.include <bsd.port.pre.mk>

do-install:
	@${ECHO_MSG} "===>  Running ${AMATCH_RUBY} to install"
	@cd ${INSTALL_WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} ${RUBY_FLAGS} ${AMATCH_RUBY} install
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
