# New ports collection makefile for:	Ruby-RDtool
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rdtool
PORTVERSION=	0.6.12
PORTREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www2.pos.to/~tosh/ruby/rdtool/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${DEPEND_RUBY_AMSTD} \
		racc:${PORTSDIR}/devel/ruby-racc

USE_RUBY=	yes
USE_RUBY_FEATURES=	optparse strscan

RUBY_MODNAME=	rd

RUBY_SHEBANG_FILES=	 ${WRKSRC}/rmi2html.rb

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

DOCS_EN=	README.html	doc/rd-draft.rd		doc/rd-draft.html
DOCS_JA=	README.ja.html	doc/rd-draft.rd.ja	doc/rd-draft.ja.html

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} rdtoolconf.rb

post-patch:
	${RUBY} -i -pe 'gsub %r"/usr/local\b", "${PREFIX}"' ${WRKSRC}/utils/rdswap.rb

pre-build:
	@cd ${WRKSRC}; \
	${LN} -s missing/strscan.rb

.if !defined(NOPORTDOCS)
post-build:
.for f in README.rd.ja doc/rd-draft.rd doc/rd-draft.rd.ja
	cd ${WRKSRC}; ${RUBY} -I. rd2 -r rd/rd2html-lib.rb ${f} \
		> ${f:S/.rd.ja$/.ja.html/:S/.rd$/.html/}
.endfor
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rmi2html.rb ${PREFIX}/bin/
	${LN} -sf rmi2html.rb ${PREFIX}/bin/rmi2html
	${INSTALL_DATA} ${WRKSRC}/rd/rd2rmi-lib.rb ${RUBY_SITELIBDIR}/rd/
	${INSTALL_SCRIPT} ${WRKSRC}/utils/rdswap.rb ${PREFIX}/bin/rdswap
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/rd/dot.rd2rc ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
