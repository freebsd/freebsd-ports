# Created by: Fumihiko Kimura <jfkimura@yahoo.co.jp>
# $FreeBSD$

PORTNAME=	tdiary
PORTVERSION=	3.2.2
CATEGORIES?=	www ruby
MASTER_SITES=	http://www.tdiary.org/download/
DISTNAME=	${PORTNAME}-full-${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Web-based diary system (like weblog) written in Ruby

LICENSE=	GPLv2

RUN_DEPENDS=	hikidoc:${PORTSDIR}/textproc/ruby-hikidoc \
		rubygem-imagesize>=0.1.1:${PORTSDIR}/graphics/rubygem-imagesize \
		rubygem-json_pure>=1.7.7:${PORTSDIR}/devel/rubygem-json_pure

NO_BUILD=	yes
USE_RUBY=	yes
RUBY_REQUIRE=	Ruby >= 185

RUBY_SHEBANG_FILES=	index.fcgi \
			index.rb \
			update.fcgi \
			update.rb \
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
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}
WWWDIR=		${PREFIX}/www/${UNIQUENAME}

TDIARY_SCRIPT=	${UNIQUENAME}-inst.rb

#TDIARY_LANG	ja:Japanese en:English
.if !defined(TDIARY_LANG) || ( defined(TDIARY_LANG) && ${TDIARY_LANG} != ja )
TDIARY_LANG=	en
.endif

REINPLACE_ARGS=	-i ''

OPTIONS_DEFINE=	DOCS NORA
OPTIONS_DEFAULT=	NORA

NORA_DESC=	Use Nora

NO_STAGE=	yes
.include <bsd.port.options.mk>

pre-patch:
	@${RM} ${WRKSRC}/.coveralls.yml
	@${RM} ${WRKSRC}/.gitignore
	@${RM} ${WRKSRC}/.travis.yml
	@${RM} ${WRKSRC}/Capfile
	@${RM} ${WRKSRC}/Gemfile
	@${RM} ${WRKSRC}/Gemfile.lock
	@${RM} ${WRKSRC}/LICENSE
	@${RM} ${WRKSRC}/Procfile
	@${RM} ${WRKSRC}/Rakefile
	@${RM} ${WRKSRC}/config.ru
	@${RM} -r ${WRKSRC}/public
	@${RM} -r ${WRKSRC}/spec
	@${RM} -r ${WRKSRC}/test
	@${RM} -r ${WRKSRC}/vendor/hikidoc-0.0.6
	@${RM} -r ${WRKSRC}/vendor/imagesize-0.1.1/*
	@${RM} -r ${WRKSRC}/vendor/json_pure-1.7.7
	@${MV} ${WRKSRC}/ChangeLog ${WRKSRC}/doc
	@${MV} ${WRKSRC}/README.md ${WRKSRC}/doc

post-patch:
	@${RUBY} -i -pe "sub %r|((\s*)require 'json')|, %Q|\\\2require 'rubygems'\n\\\1|" ${WRKSRC}/tdiary.rb

pre-install:
	@${SED} -e 's,#!/usr/bin/env ruby,#!${RUBY},' \
		${WRKDIR}/tdiaryinst.rb > ${WRKDIR}/${TDIARY_SCRIPT}
	@${REINPLACE_CMD} '/#!\/usr\/bin\/env ruby/d' ${WRKSRC}/misc/convert2.rb
	@${REINPLACE_CMD} '/#!\/usr\/bin\/env ruby/d' ${WRKSRC}/misc/migrate.rb

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${TDIARY_SCRIPT} ${PREFIX}/bin
	@-${MKDIR} ${WWWDIR}
	@${TAR} --exclude "doc" -C ${WRKSRC} -cf - . | ${TAR} --unlink -C ${WWWDIR} -xf -
	@${LN} -sf ${LOCALBASE}/lib/ruby/gems/${RUBY_VER}/gems/imagesize-0.1.1/lib ${WWWDIR}/vendor/imagesize-0.1.1/lib
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}
	@${ECHO_CMD} bin/${TDIARY_SCRIPT} >> ${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

x-generate-plist:
	${FIND} ${WWWDIR} -type f -o -type l | ${SORT} | ${SED} -e 's,${WWWDIR},%%WWWDIR%%,g' > pkg-plist.new
	${FIND} ${WWWDIR} -type d -depth | ${SORT} -r | ${SED} -e 's,${WWWDIR},@dirrm %%WWWDIR%%,g' >> pkg-plist.new

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
.if !defined(RUBY_PROVIDED)
IGNORE=	requires Ruby 1.9.1 or later
.endif
.endif

.if ${RUBY_VER} == 1.8
.if !defined(RUBY_PROVIDED)
IGNORE=	requires Ruby 1.8.5 or later
.endif
RUN_DEPENDS+=	${DEPEND_RUBY_ICONV}
.if ${PORT_OPTIONS:MNORA}
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/web/escape_ext.so:${PORTSDIR}/www/ruby-nora
.endif
.endif

.include <bsd.port.post.mk>
