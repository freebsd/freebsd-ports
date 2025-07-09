PORTNAME=	writefreely
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.1
PORTREVISION=	5
CATEGORIES=	www textproc

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Clean, Markdown-based publishing platform made for writers
WWW=		https://writefreely.org

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_DISTFILES_CC-BY-NC-SA-4.0=	writefreely-documentation-v0.13.1_GH0.tar.gz

USES=		go:modules
USE_GITHUB=	nodefault
USE_RC_SUBR=	writefreely
GO_MODULE=	github.com/writefreely/writefreely
GO_TARGET=	./cmd/writefreely

SUB_FILES=	config.ini.sample pkg-message
USERS=		writefreely
GROUPS=		writefreely

OPTIONS_DEFINE=		DOCS SQLITE3
OPTIONS_DEFAULT=	CSS_DIST SQLITE3
OPTIONS_SINGLE=		CSS
OPTIONS_SINGLE_CSS=	CSS_DIST CSS_LESSC

CSS_DESC=			Stylesheets
CSS_DIST_DESC=			Use pre-generated stylesheets
CSS_LESSC_DESC=			Generate stylesheets with lessc (requires npm)
CSS_DIST_MASTER_SITES=		LOCAL/fuz:css
CSS_DIST_DISTFILES=		writefreely-css-${DISTVERSION}.tar.gz:css
CSS_LESSC_BUILD_DEPENDS=	npm:www/npm
CSS_LESSC_VARS=			LEGAL_PACKAGE=yes \
				NO_PACKAGE="uses www/npm to fetch files at build time (option CSS_LESSC)"
DOCS_GH_TUPLE=			writefreely:documentation:v${DISTVERSION}:docs
DOCS_VARS=			LICENSE+=CC-BY-NC-SA-4.0 \
				LICENSE_COMB=multi
SQLITE3_VARS=			GO_BUILDFLAGS+=-tags=sqlite

# download the lessc program with npm for rolling the writefreely-css distfile
${WRKDIR}/npm/bin/lessc:
	@${ECHO_MSG} "=> downloading the lessc utility with NPM"
	${MKDIR} ${WRKDIR}/npm
	npm -C ${WRKDIR}/npm -g install less@3.5.3
	npm -C ${WRKDIR}/npm -g install less-plugin-clean-css

# Packaging node.js applications is a PITA, so supply pre-generated CSS files as
# a custom distfile using lessc, a node.js application.
do-build-CSS_LESSC-on: ${WRKDIR}/npm/bin/lessc
	@${ECHO_MSG} "=> generating CSS files with lessc"
	${RM} -r ${WRKDIR}/css
	${MKDIR} ${WRKDIR}/css
	cd ${WRKSRC}/less && ${WRKDIR}/npm/bin/lessc app.less --clean-css="--s1 --advanced" ${WRKDIR}/css/write.css
	cd ${WRKSRC}/less && ${WRKDIR}/npm/bin/lessc fonts.less --clean-css="--s1 --advanced" ${WRKDIR}/css/fonts.css
	cd ${WRKSRC}/less && ${WRKDIR}/npm/bin/lessc icons.less --clean-css="--s1 --advanced" ${WRKDIR}/css/icons.css
	cd ${WRKSRC}/less && ${WRKDIR}/npm/bin/lessc prose.less --clean-css="--s1 --advanced" ${WRKDIR}/css/prose.css
	${TAR} -z -c -f ${WRKDIR}/writefreely-css-${DISTVERSION}.tar.gz -C ${WRKDIR} css

do-install-DOCS-on:
	cd ${WRKSRC_docs} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} '! -depth 1'

post-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/keys
	${INSTALL_DATA} ${WRKDIR}/config.ini.sample ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} pages ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} static ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKDIR}/css/*.css ${STAGEDIR}${WWWDIR}/static/css/
	cd ${WRKSRC} && ${COPYTREE_SHARE} templates ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
