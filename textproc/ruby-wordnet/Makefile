# New ports collection makefile for:	Ruby-WordNet
# Date created:		29 September 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	wordnet
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.devEiate.org/code/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	Ruby-WordNet-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby interface to the WordNet(R) Lexical Database

BUILD_DEPENDS=	${WORDNET_DIR}/adj.exc:${PORTSDIR}/textproc/wordnet \
		${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb

BROKEN=		"Segfault during build"

WORDNET_DIR=	${LOCALBASE}/share/WordNet-2.0

USE_BZIP2=	yes
USE_RUBY=	yes
USE_RUBY_RDOC=	yes

DOCS=		ChangeLog README TODO doc

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

.if ${RUBY_VER} < 1.8
IGNORE=		only works with ruby 1.8 or later
.endif

do-build:
	cd ${BUILD_WRKSRC}; yes | ${RUBY} convertdb.rb ${WORDNET_DIR}
.if !defined(NOPORTDOCS)
# This requires the latest rdoc snapshot from CVS on SourceForge.
#	cd ${BUILD_WRKSRC}; ${RUBY} docs/makedocs.rb
	cd ${BUILD_WRKSRC}; ${RUBY_RDOC}
.endif

do-install:
	cd ${INSTALL_WRKSRC}; ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
