# New ports collection makefile for:	Ruby-RDtool
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rdtool
PORTVERSION=	0.6.5
CATEGORIES=	textproc	# ruby
MASTER_SITES=	http://www2.pos.to/~tosh/ruby/rdtool/archive/
PKGNAMEPREFIX=	ruby-

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		racc:${PORTSDIR}/devel/ruby-racc \
		${LOCALBASE}/lib/ruby/site_ruby/${RUBY_VER}/${RUBY_ARCH}/strscan.so:${PORTSDIR}/devel/ruby-strscan \
		${LOCALBASE}/lib/ruby/site_ruby/optparse.rb:${PORTSDIR}/devel/ruby-optparse
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		${LOCALBASE}/lib/ruby/site_ruby/${RUBY_VER}/${RUBY_ARCH}/strscan.so:${PORTSDIR}/devel/ruby-strscan \
		${LOCALBASE}/lib/ruby/site_ruby/optparse.rb:${PORTSDIR}/devel/ruby-optparse

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY=		${LOCALBASE}/bin/ruby
RUBY_VER=	1.4
RUBY_ARCH=	${ARCH}-freebsd${OSREL}

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} rdtoolconf.rb

post-patch:
	${PERL} -i -pe 's,/usr/local,${PREFIX},g' ${WRKSRC}/utils/rdswap.rb

pre-build:
	@cd ${WRKSRC}; \
	${LN} -s missing/strscan.rb

post-build:
	@cd ${WRKSRC}; \
	${RUBY} -I. rd2 -r rd/rd2html-lib.rb README.rd.ja > README.ja.html; \
	${RUBY} -I. rd2 -r rd/rd2html-lib.rb doc/dev-note.rd.ja > doc/dev-note.ja.html; \
	${RUBY} -I. rd2 -r rd/rd2html-lib.rb doc/rd-draft.rd > doc/rd-draft.html; \
	${RUBY} -I. rd2 -r rd/rd2html-lib.rb doc/rd-draft.rd.ja > doc/rd-draft.ja.html

post-install:
	${MKDIR} ${PREFIX}/share/examples/ruby/rd
	${CP} ${PREFIX}/lib/ruby/site_ruby/${RUBY_VER}/rd/dot.rd2rc ${PREFIX}/share/examples/ruby/rd/
	${MKDIR} ${EMACSLISPDIR}
	${INSTALL_DATA} ${WRKSRC}/utils/rd-mode.el ${EMACSLISPDIR}/
	${MKDIR} ${XEMACSLISPDIR}
	${LN} -sf ${EMACSLISPDIR}/rd-mode.el ${XEMACSLISPDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/utils/rdswap.rb ${PREFIX}/bin/rdswap
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ruby/rd/ja
	${INSTALL_DATA} ${WRKSRC}/README.html ${PREFIX}/share/doc/ruby/rd/
	${INSTALL_DATA} ${WRKSRC}/README.ja.html ${PREFIX}/share/doc/ruby/rd/ja/
	${INSTALL_DATA} ${WRKSRC}/doc/dev-note.ja.html ${PREFIX}/share/doc/ruby/rd/ja/
	${INSTALL_DATA} ${WRKSRC}/doc/rd-draft.html ${PREFIX}/share/doc/ruby/rd/
	${INSTALL_DATA} ${WRKSRC}/doc/rd-draft.ja.html ${PREFIX}/share/doc/ruby/rd/ja/
.endif

.include <bsd.port.mk>
