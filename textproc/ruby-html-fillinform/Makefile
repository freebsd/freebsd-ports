# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	html-fillinform
PORTVERSION=	0.24
CATEGORIES=	textproc www ruby
MASTER_SITES=	http://shebang.jp/src/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby library that automatically inserts form data into HTML

BROKEN=		Not stage friendly, no more public distfiles

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS_EN=	ChangeLog \
		README \
		fillinform.rd
DOCS_JA=	fillinform.ja.rd

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/example/ ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
