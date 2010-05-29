# New ports collection makefile for:	ruby-progressbar
# Date created:		2008-08-25
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	progressbar
PORTVERSION=	0.9
CATEGORIES=	misc ruby
MASTER_SITES=	http://0xcc.net/ruby-progressbar/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A text progress bar library for Ruby

USE_RUBY=	yes
NO_BUILD=	yes

RUBY_RD_FILES=	progressbar.en.rd progressbar.ja.rd
DOCS=	ChangeLog ${RUBY_RD_FILES}

do-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${PORTNAME}.rb ${RUBY_SITELIBDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	cd ${INSTALL_WRKSRC}; ${INSTALL_DATA} ${DOCS} ${RUBY_MODDOCDIR}
.endif

.include <bsd.port.mk>
