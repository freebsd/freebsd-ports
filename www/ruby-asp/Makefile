# New ports collection makefile for:	Ruby-ASP
# Date created:		23 August 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	asp
PORTVERSION=	0.2.6
CATEGORIES=	www ruby
MASTER_SITES=	http://webtime-project.net/ruby-asp/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}_${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	An Active Server Pages port to Apache with Ruby scripting

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

WRKSRC=		${WRKDIR}/ruby-${PORTNAME}

RUBY_RD_FILES=	doc/classes.en.rd \
		doc/install.en.rd \
		doc/subsmatch.en.rd \
		doc/index.en.rd

DOCS=		AUTHORS \
		README \
		${RUBY_RD_FILES} \
		${RUBY_RD_HTML_FILES}
EXAMPLES=	tests/*

post-build:
.if !defined(NOPORTDOCS) && defined(RUBY_RD_HTML)
	cd ${BUILD_WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}
.endif

post-install: doc-install

.include <bsd.port.mk>

doc-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif
