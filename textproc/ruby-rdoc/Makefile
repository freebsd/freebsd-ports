# New ports collection makefile for:	RDoc
# Date created:		26 December 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rdoc
PORTVERSION=	0.0.0.a4
CATEGORIES=	textproc ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:E:S/a/alpha-/}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

DOCS=		ChangeLog README ToDo

do-install:
	cd ${WRKSRC}; ${RUBY} ./install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}/markup
	${INSTALL_DATA} ${WRKSRC}/markup/sample/sample.rb ${RUBY_EXAMPLESDIR}/${PORTNAME}/markup
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
