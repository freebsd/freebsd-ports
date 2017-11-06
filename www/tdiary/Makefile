# Created by: Fumihiko Kimura <jfkimura@yahoo.co.jp>
# $FreeBSD$

PORTNAME=	tdiary
PORTVERSION=	5.0.6
CATEGORIES?=	www ruby
MASTER_SITES=	https://github.com/tdiary/tdiary-core/releases/download/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-full-v${PORTVERSION}

MAINTAINER=	yasu@utahime.org
COMMENT=	Web-based diary system (like weblog) written in Ruby

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bundler>=1.14.6:sysutils/rubygem-bundler \
		rubygem-emot>=0.0.4:textproc/rubygem-emot \
		rubygem-fastimage>=2.1.0:graphics/rubygem-fastimage \
		rubygem-hikidoc>=0.1.0:textproc/rubygem-hikidoc \
		rubygem-mail>=2.6.6:mail/rubygem-mail \
		rubygem-rack16>=1.6.8:www/rubygem-rack16 \
		rubygem-rake>=12.1.0:devel/rubygem-rake

USES=		shebangfix
USE_RUBY=	yes
NO_ARCH=	yes
NO_BUILD=	yes

SHEBANG_FILES=	bin/tdiary \
		index.fcgi \
		index.rb \
		misc/convert2.rb \
		misc/migrate.rb \
		misc/plugin/xmlrpc/xmlrpc.rb \
		update.fcgi \
		update.rb

DOCFILES=	HOWTO-authenticate-in-rack HOWTO-make-io \
		HOWTO-make-plugin HOWTO-make-theme \
		HOWTO-testing-tDiary HOWTO-use-plugin \
		HOWTO-write-tDiary.en HOWTO-write-tDiary \
		INSTALL-paas INSTALL README.en \
		README UPGRADE
HTML=	${DOCFILES:S/$/.html/}
MD=	${DOCFILES:S/$/.md/}
PORTDOCS=	ChangeLog doc.css ${HTML} ${MD}

PLIST_SUB=	TDIARY_SCRIPT=${TDIARY_SCRIPT} \
		WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP}
SUB_FILES=	pkg-message tdiaryinst.rb
SUB_LIST+=	TDIARY_LANG=${TDIARY_LANG} \
		TDIARY_SCRIPT=${TDIARY_SCRIPT}
WRKSRC=		${WRKDIR}/${PORTNAME}-v${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
WWWDIR=		${PREFIX}/www/${PKGBASE}

TDIARY_SCRIPT=	${PKGBASE}-inst.rb

#TDIARY_LANG	ja:Japanese en:English
.if !defined(TDIARY_LANG) || ( defined(TDIARY_LANG) && ${TDIARY_LANG} != ja )
TDIARY_LANG=	en
.endif

REINPLACE_ARGS=	-i ''

OPTIONS_DEFINE=	DOCS

pre-patch:
	@${RM} ${WRKSRC}/.coveralls.yml
	@${RM} ${WRKSRC}/.dockerignore
	@${RM} ${WRKSRC}/.editorconfig
	@${RM} ${WRKSRC}/.gitignore
	@${RM} ${WRKSRC}/.travis.yml
	@${RM} ${WRKSRC}/Dockerfile
	@${RM} ${WRKSRC}/Gemfile.lock
	@${RM} ${WRKSRC}/Procfile
	@${RM} ${WRKSRC}/Rakefile
	@${RM} ${WRKSRC}/config.ru
	@${RM} ${WRKSRC}/tdiary.gemspec
	@${RM} ${WRKSRC}/tmp/.gitkeep
	@${RM} -r ${WRKSRC}/.bundle
	@${RM} -r ${WRKSRC}/misc/lib/bundler-1.15.4
	@${RM} -r ${WRKSRC}/public
	@${RM} -r ${WRKSRC}/spec
	@${RM} -r ${WRKSRC}/test
	@${RM} -r ${WRKSRC}/vendor
	@${MV} ${WRKSRC}/ChangeLog ${WRKSRC}/doc
	@${MV} ${WRKSRC}/README.md ${WRKSRC}/doc

pre-install:
	@${SED} -e 's,#!/usr/bin/env ruby,#!${RUBY},' \
		${WRKDIR}/tdiaryinst.rb > ${WRKDIR}/${TDIARY_SCRIPT}
	@${REINPLACE_CMD} 's!%%LOCALBASE%%!${LOCALBASE}!g' \
		${WRKSRC}/misc/convert2.rb \
		${WRKSRC}/misc/migrate.rb
	@${FIND} ${WRKSRC} -name "*.orig" -delete

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${TDIARY_SCRIPT} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${TAR} --exclude doc --exclude LICENSE -C ${WRKSRC} -cf - . | ${TAR} --unlink -C ${STAGEDIR}${WWWDIR} -xf -

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

x-generate-plist: stage
	${ECHO_CMD} bin/%%TDIARY_SCRIPT%% > pkg-plist.new
	${ECHO_CMD} @owner %%WWWOWN%% >> pkg-plist.new
	${ECHO_CMD} @group %%WWWGRP%% >> pkg-plist.new
	${FIND} ${STAGEDIR}${WWWDIR} -type f -o -type l | ${SORT} | ${SED} -e 's,${STAGEDIR}${WWWDIR},%%WWWDIR%%,g' >> pkg-plist.new
	${FIND} ${STAGEDIR}${WWWDIR} -type d -depth | ${SORT} -r | ${SED} -e 's,${STAGEDIR}${WWWDIR},@dir %%WWWDIR%%,g' >> pkg-plist.new
	${ECHO_CMD} @owner >> pkg-plist.new
	${ECHO_CMD} @group >> pkg-plist.new

.include <bsd.port.mk>
