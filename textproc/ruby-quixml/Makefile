# New ports collection makefile for:	ruby-quixml
# Date created:		10 September 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	quixml
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/89/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Fast XML API for Ruby written in C

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

DOCS=		BUGS DOC.html CHANGELOG README TODO

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
