# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rttool
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.rubyist.net/~rubikitch/archive/ \
		LOCAL/tota/ruby-rttool
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	${RUBY_PKGNAMEPREFIX:S|${RUBY_SUFFIX}-||}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	RT into HTML and plain text converter

LICENSE=	RUBY

USE_RUBY=	yes
USES=		shebangfix
USE_RUBY_SETUP=	yes
USE_RUBY_RDTOOL=	yes

SHEBANG_FILES=	bin/rt/* lib/rt/*
RUBY_MODNAME=	rt

DOCS_EN=	rttool.en.html rttool.en.rd
DOCS_JA=	rttool.ja.html rttool.ja.rd

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
.endfor
	@${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${RUBY_MODEXAMPLESDIR}

.include <bsd.port.mk>
