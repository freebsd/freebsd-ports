# New ports collection makefile for:    tdiary
# Date created:                 21 May 2003
# Whom:                         Fumihiko Kimura <jfkimura@yahoo.co.jp>
#
# $FreeBSD$
#

PORTNAME=	tdiary
PORTVERSION=	3.1.1
CATEGORIES?=	www ruby
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/ \
		http://www.tdiary.org/download/
DISTNAME=	${PORTNAME}-full-${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A Web-based diary system (like weblog) written in Ruby

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/doc/COPYING

RUN_DEPENDS=	hikidoc:${PORTSDIR}/textproc/ruby-hikidoc \
		rubygem-imagesize>=0.1.1:${PORTSDIR}/graphics/rubygem-imagesize \
		rubygem-json_pure>=1.6.1:${PORTSDIR}/devel/rubygem-json_pure

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
			misc/plugin/xmlrpc/xmlrpc.rb \
			misc/standalone_cgi/bin/server

PORTDOCS=	ChangeLog COPYING HOWTO-make-io.rd HOWTO-make-plugin.html \
		HOWTO-make-theme.html HOWTO-use-plugin.html \
		HOWTO-write-tDiary.en.html HOWTO-write-tDiary.html INSTALL.html \
		README.en.html README.html README.md UPGRADE doc.css

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
.if !defined(WITHOUT_TDIARY_NORA)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/web/escape_ext.so:${PORTSDIR}/www/ruby-nora
.endif
.endif

post-extract:
	@${RM} ${WRKSRC}/.gitignore
	@${RM} ${WRKSRC}/.rspec
	@${RM} ${WRKSRC}/.travis.yml
	@${RM} ${WRKSRC}/Capfile
	@${RM} ${WRKSRC}/Gemfile
	@${RM} ${WRKSRC}/Gemfile.lock
	@${RM} ${WRKSRC}/Rakefile
	@${RM} ${WRKSRC}/config.ru
	@${RM} -r ${WRKSRC}/public
	@${RM} -r ${WRKSRC}/spec
	@${RM} -r ${WRKSRC}/vendor/hikidoc-0.0.6
	@${RM} -r ${WRKSRC}/vendor/imagesize-0.1.1/*
	@${RM} -r ${WRKSRC}/vendor/json_pure-1.6.1
	@${MV} ${WRKSRC}/ChangeLog ${WRKSRC}/doc
	@${MV} ${WRKSRC}/README.md ${WRKSRC}/doc
	@cd ${WRKSRC} && ${MV} doc ${WRKDIR}

post-patch:
	${RUBY} -i -pe "sub %r|((\s*)require 'json')|, %Q|\\\2require 'rubygems'\n\\\1|" ${WRKSRC}/tdiary.rb

pre-install:
	@${SED} -e 's,#!/usr/bin/env ruby,#!${RUBY},' \
		${WRKDIR}/tdiaryinst.rb > ${WRKDIR}/${TDIARY_SCRIPT}
	@${REINPLACE_CMD} '/#!\/usr\/bin\/env ruby/d' ${WRKSRC}/misc/convert2.rb
	@${REINPLACE_CMD} '/#!\/usr\/bin\/env ruby/d' ${WRKSRC}/misc/migrate.rb

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${TDIARY_SCRIPT} ${PREFIX}/bin
	@-${MKDIR} ${WWWDIR}
	@${CP} -pR ${WRKSRC}/ ${WWWDIR}
	@${LN} -s ${LOCALBASE}/lib/ruby/gems/${RUBY_VER}/gems/imagesize-0.1.1/lib ${WWWDIR}/vendor/imagesize-0.1.1/lib
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}
	@${ECHO_CMD} bin/${TDIARY_SCRIPT} >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKDIR}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

x-generate-plist:
	${FIND} ${WWWDIR} -type f -o -type l | ${SORT} | ${SED} -e 's,${WWWDIR},%%WWWDIR%%,g' > pkg-plist.new
	${FIND} ${WWWDIR} -type d -depth | ${SORT} -r | ${SED} -e 's,${WWWDIR},@dirrm %%WWWDIR%%,g' >> pkg-plist.new

.include <bsd.port.post.mk>
