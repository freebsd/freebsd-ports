# New ports collection makefile for:	Ruby-RDtool
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rdtool
PORTVERSION=	0.6.5
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www2.pos.to/~tosh/ruby/rdtool/archive/
PKGNAMEPREFIX=	ruby-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		racc:${PORTSDIR}/devel/ruby-racc \
		${RUBY_SITEARCHLIBDIR}/strscan.so:${PORTSDIR}/devel/ruby-strscan \
		${RUBY_SITELIBDIR}/optparse.rb:${PORTSDIR}/devel/ruby-optparse
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		${RUBY_SITELIBDIR}/racc/parser.rb:${PORTSDIR}/devel/ruby-racc-runtime \
		${RUBY_SITEARCHLIBDIR}/strscan.so:${PORTSDIR}/devel/ruby-strscan \
		${RUBY_SITELIBDIR}/optparse.rb:${PORTSDIR}/devel/ruby-optparse

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

RUBY_SITELIBDIR?=	${LOCALBASE}/lib/ruby/site_ruby/${RUBY_VER}
RUBY_SITEARCHLIBDIR?=	${LOCALBASE}/lib/ruby/site_ruby/${RUBY_VER}/${RUBY_ARCH}

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

DOCS_EN=	README.html	doc/rd-draft.rd		doc/rd-draft.html
DOCS_JA=	README.ja.html	doc/dev-note.rd.ja	doc/rd-draft.rd.ja \
		doc/dev-note.ja.html doc/rd-draft.ja.html

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} rdtoolconf.rb

post-patch:
	${PERL} -i -pe 's,/usr/local,${PREFIX},g' ${WRKSRC}/utils/rdswap.rb

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
	${MKDIR} ${EMACSLISPDIR}
	${INSTALL_DATA} ${WRKSRC}/utils/rd-mode.el ${EMACSLISPDIR}/
	${MKDIR} ${XEMACSLISPDIR}
	${LN} -sf ${EMACSLISPDIR}/rd-mode.el ${XEMACSLISPDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/utils/rdswap.rb ${PREFIX}/bin/rdswap
.if !defined(NOPORTDOCS)
	rd2 ${PREFIX}/share/doc/ruby/optparse/ja/optparse.ja.rd \
		> ${PREFIX}/share/doc/ruby/optparse/ja/optparse.ja.html
	${MKDIR} ${PREFIX}/share/examples/ruby/rd
	${CP} ${RUBY_SITELIBDIR}/rd/dot.rd2rc ${PREFIX}/share/examples/ruby/rd/
	${MKDIR} ${PREFIX}/share/doc/ruby/rd/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/rd/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/rd/ja/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
