# New ports collection makefile for:	Ruby-xmlparser
# Date created:		9 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	xmlparser
PORTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.yoshidam.net/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${PERL_ARCHLIB}/XML/Parser/Expat.pm:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	expat.2:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	${PERL_ARCHLIB}/XML/Parser/Expat.pm:${PORTSDIR}/textproc/p5-XML-Parser
# to utilize encoding maps included in p5-XML-Parser

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
.if !defined(NOPORTDOCS)
USE_RUBY_RD=	yes
.endif

PERL_ARCHLIB=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFIGURE_ARGS=	--with-perl-enc-map
INSTALL_TARGET=	site-install

EXAMPLES_EN=	dtd/ext1.dtd	dtd/ext2.dtd	dtd/extdtd.rb	dtd/extdtd.xml \
		namespaces/namespace1.rb	namespaces/namespace1.xml \
		namespaces/namespace2.rb	namespaces/namespace2.xml \
		digesttest.rb	doctype.rb	doctype.xml	doctypei.rb \
		idattrtest.rb	my-html.rb	saxtest.rb \
		visitortest.rb	writer.rb	xmlcomments.rb	xmlstats.rb
EXAMPLES_JA=	buildertest.rb	buildertest2.rb	digesttest2.rb	document.dtd \
		gtktree.rb	index_euc.xml	index_jis.xml	index_noenc.xml \
		index_sjis.xml	index_u16.xml	index_u8.xml	treetest.rb \
		videolist.dtd	videolist.rb	videolist.xml	visitor.rb \
		xmlcheck.rb	xmlevent.rb	xmlgrep.rb	xmliter.rb \
		xpointer.rb	xpointertest.rb
RD_DOCS=	xmltree.rb	xmltreebuilder.rb	xmltreevisitor.rb

post-patch:
	${RUBY} -i -pe 'gsub /%%PREFIX%%/, "${PREFIX}"' ${WRKSRC}/lib/wget.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/xmlparser/dtd
	${MKDIR} ${RUBY_EXAMPLESDIR}/xmlparser/namespaces
	${MKDIR} ${RUBY_EXAMPLESDIR}/xmlparser/ja
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/samples/${f} \
		${RUBY_EXAMPLESDIR}/xmlparser/${f}
.endfor
.for f in ${EXAMPLES_JA}
	${INSTALL_DATA} ${WRKSRC}/samples/${f} \
		${RUBY_EXAMPLESDIR}/xmlparser/ja/${f}
.endfor
.for f in ${RD_DOCS}
	@cd ${WRKSRC}/lib; \
	${RUBY_RD} ${f} > ${f:S/.rb$/.html/}
.endfor
	${MKDIR} ${RUBY_DOCDIR}/xmlparser/ja
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/xmlparser/
	${INSTALL_DATA} ${WRKSRC}/README.ja ${RUBY_DOCDIR}/xmlparser/ja/
.for f in ${RD_DOCS:S/.rb$/.html/}
	${INSTALL_DATA} ${WRKSRC}/lib/${f} ${RUBY_DOCDIR}/xmlparser/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
