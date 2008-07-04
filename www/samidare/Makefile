# New ports collection makefile for:	samidare
# Date created:		2008-04-30
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	samidare
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	www ruby
MASTER_SITES=	http://www.a-k-r.org./samidare/

MAINTAINER=	tota@rtfm.jp
COMMENT=	A web page update checker written in Ruby

RUN_DEPENDS=	${RUBY_SITELIBDIR}/htree.rb:${PORTSDIR}/textproc/ruby-htree

USE_GMAKE=	yes
USE_RUBY=	yes

RUBY_REQUIRE=	Ruby >= 181
RUBY_SHEBANG_FILES=	main.rb rb-link rb2rm rm2rb
PORTDOCS=	README README.ja
PORTEXAMPLES=	config.yml t.latest.html

UNIQ=	/usr/bin/uniq

.include <bsd.port.pre.mk>

.if !defined(RUBY_PROVIDED)
IGNORE=		requires Ruby 1.8.1 or later
.endif

ALL_TARGET=	${PORTNAME}

post-build:
	cd ${BUILD_WRKSRC} && \
	${MV} samidare samidare.orig && \
	${UNIQ} samidare.orig samidare

do-install:
	cd ${INSTALL_WRKSRC}; ${INSTALL_SCRIPT} ${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${INSTALL_WRKSRC}; ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${INSTALL_WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
