# New ports collection makefile for:	ruby-escape
# Date created:		2011-03-29
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	escape
PORTVERSION=	0.2
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.a-k-r.org/${PORTNAME}/ \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|tota/ruby-escape|}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	${RUBY_PKGNAMEPREFIX:S|${RUBY_SUFFIX}-||}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Ruby library provides HTML/URI/shell escaping functions

USE_RUBY=	yes
NO_BUILD=	yes

DOCS=	ChangeLog README

do-install:
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/escape.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
