# New ports collection makefile for:	Ruby-xmlparser
# Date created:		9 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	xmlparser
PORTVERSION=	0.5.19
CATEGORIES=	textproc	# ruby
MASTER_SITES=	http://www.bekkoame.ne.jp/~yoshidam/
PKGNAMEPREFIX=	ruby-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		${PERL_ARCHLIB}/XML/Parser/Expat.pm:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	expat.1:${PORTSDIR}/textproc/expat
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		${PERL_ARCHLIB}/XML/Parser/Expat.pm:${PORTSDIR}/textproc/p5-XML-Parser
# to utilize encoding maps included in p5-XML-Parser

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	rd2:${PORTSDIR}/textproc/ruby-rdtool
.endif

PERL_ARCHLIB=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/mach

WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_TARGET=	site-install
PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY=		${LOCALBASE}/bin/ruby
RUBY_VER=	1.4
RUBY_ARCH=	${ARCH}-freebsd${OSREL}

EXAMPLES_EN=	dtd/ext1.dtd	dtd/ext2.dtd	dtd/extdtd.rb	dtd/extdtd.xml \
		namespaces/namespace1.rb	namespaces/namespace1.xml \
		namespaces/namespace2.rb	namespaces/namespace2.xml \
		digesttest.rb	idattrtest.rb	my-html.rb	saxtest.rb \
		visitortest.rb	writer.rb	xmlcomments.rb	xmlstats.rb
EXAMPLES_JA=	buildertest.rb	buildertest2.rb	digesttest2.rb	document.dtd \
		gtktree.rb	index_euc.xml	index_jis.xml	index_noenc.xml \
		index_sjis.xml	index_u16.xml	index_u8.xml	treetest.rb \
		videolist.dtd	videolist.rb	videolist.xml	visitor.rb \
		xmlcheck.rb	xmlevent.rb	xmlgrep.rb	xmliter.rb \
		xpointer.rb	xpointertest.rb
RD_DOCS=	xmltree.rb	xmltreebuilder.rb	xmltreevisitor.rb

post-patch:
	${PERL} -i -pe 's,%%PERL_ARCHLIB%%,${PERL_ARCHLIB},g' ${WRKSRC}/extconf.rb
	${PERL} -i -pe 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/lib/wget.rb

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb

post-install:
	${MKDIR} ${PREFIX}/share/examples/ruby/xmlparser/dtd
	${MKDIR} ${PREFIX}/share/examples/ruby/xmlparser/namespaces
	${MKDIR} ${PREFIX}/share/examples/ruby/xmlparser/ja
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/samples/${f} \
		${PREFIX}/share/examples/ruby/xmlparser/${f}
.endfor
.for f in ${EXAMPLES_JA}
	${INSTALL_DATA} ${WRKSRC}/samples/${f} \
		${PREFIX}/share/examples/ruby/xmlparser/ja/${f}
.endfor
.if !defined(NOPORTDOCS)
.for f in ${RD_DOCS}
	@cd ${WRKSRC}/lib; \
	rd2 ${f} > ${f:S/.rb$/.html/}
.endfor
	${MKDIR} ${PREFIX}/share/doc/ruby/xmlparser/ja
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ruby/xmlparser/
	${INSTALL_DATA} ${WRKSRC}/README.ja ${PREFIX}/share/doc/ruby/xmlparser/ja/
.for f in ${RD_DOCS:S/.rb$/.html/}
	${INSTALL_DATA} ${WRKSRC}/lib/${f} ${PREFIX}/share/doc/ruby/xmlparser/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
