# New ports collection makefile for:	rabbit
# Date created:		2010-08-01
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rabbit
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	misc ruby
MASTER_SITES=	http://rabbit-shockers.org/download/ \
		LOCAL
MASTER_SITE_SUBDIR=	tota/${PORTNAME}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	An RD-document-based presentation application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2 \
		${RUBY_SITEARCHLIBDIR}/rsvg2.so:${PORTSDIR}/graphics/ruby-rsvg2 \
		${RUBY_SITEARCHLIBDIR}/poppler.so:${PORTSDIR}/x11-toolkits/ruby-poppler \
		hikidoc:${PORTSDIR}/textproc/ruby-hikidoc \
		rubygem-nokogiri>0:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-sinatra>0:${PORTSDIR}/www/rubygem-sinatra \
		rubygem-haml>0:${PORTSDIR}/www/rubygem-haml \
		rd2:${PORTSDIR}/textproc/ruby-rdtool \
		rubygem-coderay>=1.0.0:${PORTSDIR}/textproc/rubygem-coderay \
		rubygem-kramdown>0:${PORTSDIR}/textproc/rubygem-kramdown

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
RUN_DEPENDS+=	rubygem-gettext>0:${PORTSDIR}/devel/rubygem-gettext
PLIST_SUB+=	NLS=""
.endif

RUBY_SHEBANG_FILES=	bin/rabbirack \
			bin/rabbirc \
			bin/rabbit \
			bin/rabbit-command \
			bin/rabbit-theme-manager \
			bin/rabbiter \
			bin/rabrick

PORTDOCS=	*
PORTEXAMPLES=	*
PORTDATA=	*

OPTIONS_DEFINE=	MIMETEX TWITTER
MIMETEX_DESC=	Run with mimetex
TWITTER_DESC=	Run with Twitter

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMIMETEX}
RUN_DEPENDS+=	${LOCALBASE}/www/mimetex/cgi-bin/mimetex.cgi:${PORTSDIR}/www/mimetex
.endif

.if ${PORT_OPTIONS:MTWITTER}
RUN_DEPENDS+=	rubygem-twitter_oauth>=0:${PORTSDIR}/security/rubygem-twitter_oauth \
		rubygem-twitter-stream>=0:${PORTSDIR}/net/rubygem-twitter-stream
.endif

post-patch:
	${RM} ${WRKSRC}/bin/rabwii
	${RUBY} -i -pe 'sub %r|((\s*)require "rack")|, %Q|\\2require "rubygems"\n\\1|' ${WRKSRC}/bin/rabbirack
	${RUBY} -i -pe 'sub %r|(require "hikidoc")|, %Q|require "rubygems"\n\\1|' ${WRKSRC}/lib/rabbit/parser/wiki.rb
	${RUBY} -i -pe "sub %r|((\s*)require 'twitter_oauth')|, %Q|\\\2require 'rubygems'\n\\\1|" ${WRKSRC}/lib/rabbit/twitter.rb
	${RUBY} -i -pe "sub %r|(require 'coderay')|, %Q|require 'rubygems'\n\\\1|" ${WRKSRC}/lib/rabbit/parser/ext/coderay.rb
.if ${PORT_OPTIONS:MMIMETEX}
	${REINPLACE_CMD} -e 's|"mimetex.cgi"|"${PREFIX}/www/mimetex/cgi-bin/mimetex.cgi"|' \
		${WRKSRC}/lib/rabbit/parser/ext/tex.rb
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/sample && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif
.if defined(NOPORTDATA)
	@${RM} -r ${DATADIR}
.endif

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	${CP} /dev/null pkg-plist.new
.for f in ${RUBY_SHEBANG_FILES}
	${ECHO} ${f} >> pkg-plist.new
.endfor
	${FIND} ${RUBY_SITELIBDIR}/rabbit -type f | ${SORT} | ${SED} -e 's,${RUBY_SITELIBDIR},%%RUBY_SITELIBDIR%%,' >> pkg-plist.new
	${FIND} ${PREFIX}/share/locale -type f -name rabbit.mo | ${SORT} | ${SED} -e 's,^${PREFIX}/,%%NLS%%,' >> pkg-plist.new
	${FIND} ${RUBY_SITELIBDIR}/rabbit -type d -depth | ${SORT} -r | ${SED} -e 's,${RUBY_SITELIBDIR},@dirrm %%RUBY_SITELIBDIR%%,' >> pkg-plist.new

.include <bsd.port.mk>
