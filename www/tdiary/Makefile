# Created by: Fumihiko Kimura <jfkimura@yahoo.co.jp>
# $FreeBSD$

PORTNAME=	tdiary
PORTVERSION=	4.0.1
CATEGORIES?=	www ruby
MASTER_SITES=	http://www.tdiary.org/download/
DISTNAME=	${PORTNAME}-full-v${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Web-based diary system (like weblog) written in Ruby

LICENSE=	GPLv2

RUN_DEPENDS=	rubygem-fastimage>=1.5.0:${PORTSDIR}/graphics/rubygem-fastimage \
		hikidoc:${PORTSDIR}/textproc/ruby-hikidoc \
		rubygem-multi_json>=1.7.7:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-rack>=0:${PORTSDIR}/www/rubygem-rack

NO_BUILD=	yes
USE_RUBY=	yes
RUBY_REQUIRE=	Ruby >= 193

RUBY_SHEBANG_FILES=	index.fcgi \
			index.rb \
			update.fcgi \
			update.rb \
			bin/tdiary \
			misc/convert2.rb \
			misc/migrate.rb \
			misc/plugin/amazon/amazonimg.rb \
			misc/plugin/squeeze.rb \
			misc/plugin/xmlrpc/xmlrpc.rb

DOCFILES=	HOWTO-authenticate-in-rack HOWTO-make-io \
		HOWTO-make-plugin HOWTO-make-theme \
		HOWTO-testing-tDiary HOWTO-use-plugin \
		HOWTO-write-tDiary.en HOWTO-write-tDiary \
		INSTALL-paas INSTALL README.en \
		README UPGRADE
HTML=	${DOCFILES:S/$/.html/}
MD=	${DOCFILES:S/$/.md/}
PORTDOCS=	ChangeLog doc.css ${HTML} ${MD}

SUB_FILES=	pkg-message tdiaryinst.rb
SUB_LIST+=	TDIARY_LANG=${TDIARY_LANG} \
		TDIARY_SCRIPT=${TDIARY_SCRIPT}
WRKSRC=		${WRKDIR}/${PORTNAME}-v${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}
WWWDIR=		${PREFIX}/www/${UNIQUENAME}

TDIARY_SCRIPT=	${UNIQUENAME}-inst.rb

#TDIARY_LANG	ja:Japanese en:English
.if !defined(TDIARY_LANG) || ( defined(TDIARY_LANG) && ${TDIARY_LANG} != ja )
TDIARY_LANG=	en
.endif

REINPLACE_ARGS=	-i ''

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
.if !defined(RUBY_PROVIDED)
IGNORE=	requires Ruby 1.9.3 or later
.endif
.endif

pre-patch:
	@${RM} ${WRKSRC}/.coveralls.yml
	@${RM} ${WRKSRC}/.gitignore
	@${RM} ${WRKSRC}/.travis.yml
	@${RM} ${WRKSRC}/Gemfile
	@${RM} ${WRKSRC}/Gemfile.lock
	@${RM} ${WRKSRC}/LICENSE
	@${RM} ${WRKSRC}/Procfile
	@${RM} ${WRKSRC}/Rakefile
	@${RM} ${WRKSRC}/config.ru
	@${RM} -r ${WRKSRC}/.bundle
	@${RM} -r ${WRKSRC}/misc/lib/bundler-1.3.5
	@${RM} -r ${WRKSRC}/public
	@${RM} -r ${WRKSRC}/spec
	@${RM} -r ${WRKSRC}/test
	@${RM} -r ${WRKSRC}/vendor
	@${MV} ${WRKSRC}/ChangeLog ${WRKSRC}/doc
	@${MV} ${WRKSRC}/README.md ${WRKSRC}/doc

post-patch:
	@${RUBY} -i -pe "sub %r|(.*< ::Rack::Request)|, %Q|\trequire 'rack'\n\\\1|" ${WRKSRC}/tdiary/request.rb

pre-install:
	@${SED} -e 's,#!/usr/bin/env ruby,#!${RUBY},' \
		${WRKDIR}/tdiaryinst.rb > ${WRKDIR}/${TDIARY_SCRIPT}
	@${REINPLACE_CMD} '/#!\/usr\/bin\/env ruby/d' ${WRKSRC}/misc/convert2.rb
	@${REINPLACE_CMD} '/#!\/usr\/bin\/env ruby/d' ${WRKSRC}/misc/migrate.rb

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${TDIARY_SCRIPT} ${STAGEDIR}${PREFIX}/bin
	@-${MKDIR} ${STAGEDIR}${WWWDIR}
	@${TAR} --exclude "doc" -C ${WRKSRC} -cf - . | ${TAR} --unlink -C ${STAGEDIR}${WWWDIR} -xf -

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}
	@${ECHO_CMD} bin/${TDIARY_SCRIPT} >> ${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

x-generate-plist:
	${FIND} ${WWWDIR} -type f -o -type l | ${SORT} | ${SED} -e 's,${WWWDIR},%%WWWDIR%%,g' > pkg-plist.new
	${FIND} ${WWWDIR} -type d -depth | ${SORT} -r | ${SED} -e 's,${WWWDIR},@dirrm %%WWWDIR%%,g' >> pkg-plist.new

.include <bsd.port.post.mk>
