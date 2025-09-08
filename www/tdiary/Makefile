PORTNAME=	tdiary
DISTVERSION=	5.4.0
CATEGORIES?=	www ruby
MASTER_SITES=	https://github.com/tdiary/tdiary-core/releases/download/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-full-v${PORTVERSION}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Web-based diary system (like weblog) written in Ruby
WWW=		https://www.tdiary.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-base64>=0.3.0:converters/rubygem-base64 \
		rubygem-bundler>=2.0.2:sysutils/rubygem-bundler \
		rubygem-emot>=0.0.4:textproc/rubygem-emot \
		rubygem-fastimage>=2.4.0:graphics/rubygem-fastimage \
		rubygem-hikidoc>=0.1.0:textproc/rubygem-hikidoc \
		rubygem-mail>=2.8.1:mail/rubygem-mail \
		rubygem-net-smtp>=0.5.1:mail/rubygem-net-smtp \
		rubygem-rack-session>=2.1.1:www/rubygem-rack-session \
		rubygem-rack>=3.1.16,3:www/rubygem-rack \
		rubygem-rackup>=2.2.1:www/rubygem-rackup \
		rubygem-rake>=13.3.0:devel/rubygem-rake

USES=		cpe ruby shebangfix

SHEBANG_FILES=	bin/tdiary index.fcgi index.rb misc/convert2.rb misc/migrate.rb \
		misc/plugin/xmlrpc/xmlrpc.rb update.fcgi update.rb

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
WWWDIR=		${PREFIX}/www/${PKGBASE}
REINPLACE_ARGS=	-i ''
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message tdiaryinst.rb
SUB_LIST+=	TDIARY_LANG=${TDIARY_LANG} \
		TDIARY_SCRIPT=${TDIARY_SCRIPT}

WRKSRC=		${WRKDIR}/${PORTNAME}-v${PORTVERSION}
PLIST_SUB=	TDIARY_SCRIPT=${TDIARY_SCRIPT} \
		WWWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}

PORTDOCS=	${HTML} ${MD} ChangeLog doc.css

OPTIONS_DEFINE=	DOCS

DOCFILES=	HOWTO-authenticate-in-rack HOWTO-make-io HOWTO-make-plugin \
		HOWTO-make-theme HOWTO-testing-tDiary HOWTO-use-plugin \
		HOWTO-write-tDiary.en HOWTO-write-tDiary INSTALL-paas INSTALL \
		README.en README UPGRADE
HTML=		${DOCFILES:S/$/.html/}
MD=		${DOCFILES:S/$/.md/}

#TDIARY_LANG	ja:Japanese en:English
.if !defined(TDIARY_LANG) || (defined(TDIARY_LANG) && ${TDIARY_LANG} != ja)
TDIARY_LANG=	en
.endif

TDIARY_SCRIPT=	${PKGBASE}-inst.rb

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
	@${RM} -r ${WRKSRC}/.devcontainer
	@${RM} -r ${WRKSRC}/.github
	@${RM} -r ${WRKSRC}/.vscode
	@${RM} -r ${WRKSRC}/misc/lib/bundler-2.2.18
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

.include <bsd.port.mk>
