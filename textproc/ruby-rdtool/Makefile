# New ports collection makefile for:	Ruby-RDtool
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rdtool
PORTVERSION=	0.6.7
PORTREVISION=	1
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www2.pos.to/~tosh/ruby/rdtool/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	racc:${PORTSDIR}/devel/ruby-racc \
		${RUBY_SITELIBDIR}/strscan.rb:${PORTSDIR}/devel/ruby-strscan \
		${RUBY_SITELIBDIR}/optparse.rb:${PORTSDIR}/devel/ruby-optparse
RUN_DEPENDS=	${RUBY_SITELIBDIR}/racc/parser.rb:${PORTSDIR}/devel/ruby-racc-runtime \
		${RUBY_SITELIBDIR}/strscan.rb:${PORTSDIR}/devel/ruby-strscan \
		${RUBY_SITELIBDIR}/optparse.rb:${PORTSDIR}/devel/ruby-optparse

USE_RUBY=	yes

RUBY_SHEBANG_FILES=	 ${WRKSRC}/rmi2html.rb

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

DOCS_EN=	README.html	doc/rd-draft.rd		doc/rd-draft.html
DOCS_JA=	README.ja.html	doc/dev-note.rd.ja	doc/rd-draft.rd.ja \
		doc/dev-note.ja.html doc/rd-draft.ja.html

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
	@cd ${WRKSRC}; \
	${RUBY} -I. rd2 -r rd/rd2html-lib.rb README.rd.ja > README.ja.html; \
	${RUBY} -I. rd2 -r rd/rd2html-lib.rb doc/dev-note.rd.ja > doc/dev-note.ja.html; \
	${RUBY} -I. rd2 -r rd/rd2html-lib.rb doc/rd-draft.rd > doc/rd-draft.html; \
	${RUBY} -I. rd2 -r rd/rd2html-lib.rb doc/rd-draft.rd.ja > doc/rd-draft.ja.html
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rmi2html.rb ${PREFIX}/bin/
	${LN} -sf rmi2html.rb ${PREFIX}/bin/rmi2html
	${INSTALL_DATA} ${WRKSRC}/rd/rd2rmi-lib.rb ${RUBY_SITELIBDIR}/rd/
	${MKDIR} ${XEMACSLISPDIR}
	${INSTALL_DATA} ${WRKSRC}/utils/rd-mode.el ${XEMACSLISPDIR}/
	${LN} -sf ${XEMACSLISPDIR}/rd-mode.el ${EMACSLISPDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/utils/rdswap.rb ${PREFIX}/bin/rdswap
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/rd
	${CP} ${RUBY_SITELIBDIR}/rd/dot.rd2rc ${RUBY_EXAMPLESDIR}/rd/
	${MKDIR} ${RUBY_DOCDIR}/rd/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/rd/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/rd/ja/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
