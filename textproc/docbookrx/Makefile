PORTNAME=	docbookrx
DISTVERSION=	1.0.0.dev
CATEGORIES=	textproc

MAINTAINER=	swills@FreeBSD.org
COMMENT=	DocBook to AsciiDoc converter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/rake:devel/rubygem-rake \
		gem:devel/ruby-gems \
		rubygem-bundler>=1.16:sysutils/rubygem-bundler \
		rubygem-rspec>=1.2.2:devel/rubygem-rspec
RUN_DEPENDS=	rubygem-nokogiri>=1.8:textproc/rubygem-nokogiri

USE_RUBY=	yes
USE_GITHUB=	yes

OPTIONS_DEFINE=	DOCS

GH_ACCOUNT=	allanjude
GH_PROJECT=	docbookrx
GH_TAGNAME=	06cae39

GEM_ENV+=	RB_USER_INSTALL=yes
USE_LOCALE?=	en_US.UTF-8
GEM_ENV+=	LANG=${USE_LOCALE} LC_ALL=${USE_LOCALE}
RUBYGEM_ARGS=	-l --no-update-sources --ignore-dependencies \
		--install-dir  ${STAGEDIR}${PREFIX}/lib/ruby/gems/${RUBY_VER} \
		--bindir=${STAGEDIR}${PREFIX}/bin

RUBYGEMBIN=	${LOCALBASE}/bin/gem
GEMS_BASE_DIR=	lib/ruby/gems/${RUBY_VER}
GEMS_DIR=	${GEMS_BASE_DIR}/gems
DOC_DIR=	${GEMS_BASE_DIR}/doc
CACHE_DIR=	${GEMS_BASE_DIR}/cache
EXT_DIR=	${GEMS_BASE_DIR}/extensions
GEM_LIB_DIR?=	${GEMS_DIR}/${PORTNAME}-${DISTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
RUBYGEM_ARGS+=	--document rdoc,ri
.else
RUBYGEM_ARGS+=	--no-document
.endif

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${GEM_ENV} ${RUBYGEMBIN} build --force ${PORTNAME}.gemspec

do-install:
	cd ${INSTALL_WRKSRC} && ${SETENV} ${GEM_ENV} ${RUBYGEMBIN} install ${RUBYGEM_ARGS} ${PORTNAME}-${DISTVERSION}.gem -- ${CONFIGURE_ARGS}
	${RM} -r ${STAGEDIR}${PREFIX}/${GEMS_BASE_DIR}/build_info
	${FIND} ${STAGEDIR}${PREFIX}/${GEMS_BASE_DIR} -type f -name '*.so' -exec ${STRIP_CMD} {} +
	${FIND} ${STAGEDIR}${PREFIX}/${GEMS_BASE_DIR} -type f \( -name mkmf.log -or -name gem_make.out \) -delete
	${RM} -r ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/extensions \
	${STAGEDIR}${PREFIX}/${CACHE_DIR} 2> /dev/null || ${TRUE}
	${RMDIR} ${STAGEDIR}${PREFIX}/${EXT_DIR} 2> /dev/null || ${TRUE}
	${ECHO} bin/docbookrx >> ${TMPPLIST}
	${ECHO} ${GEMS_BASE_DIR}/specifications/${PORTNAME}-${DISTVERSION}.gemspec >> ${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	${FIND} -ds ${STAGEDIR}${PREFIX}/${DOC_DIR} -type f -print | ${SED} -E -e \
		's,^${STAGEDIR}${PREFIX}/?,,' >> ${TMPPLIST}
.endif
	${FIND} -ds ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR} -type f -print | ${SED} -E -e \
		's,^${STAGEDIR}${PREFIX}/?,,' >> ${TMPPLIST}
		@if [ -d ${STAGEDIR}${PREFIX}/${EXT_DIR} ]; then \
			${FIND} -ds ${STAGEDIR}${PREFIX}/${EXT_DIR} -type f -print | ${SED} -E -e \
			's,^${STAGEDIR}${PREFIX}/?,,' >> ${TMPPLIST} ; \
		fi

.include <bsd.port.mk>
