PORTNAME=	immich-kiosk
DISTVERSIONPREFIX=	v
DISTVERSION=	0.47.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://registry.npmjs.org/choices.js/-/:choices \
		https://registry.npmjs.org/date-fns/-/:datefns \
		https://registry.npmjs.org/htmx-ext-sse/-/:htmxsse \
		https://registry.npmjs.org/htmx.org/-/:htmx
DISTFILES=	choices.js-${_CHOICESJS_VER}.tgz:choices \
		date-fns-${_DATEFNS_VER}.tgz:datefns \
		htmx-ext-sse-${_HTMXSSE_VER}.tgz:htmxsse \
		htmx.org-${_HTMX_VER}.tgz:htmx

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Configurable slideshows for displaying Immich assets
WWW=		https://github.com/damongolding/immich-kiosk

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	esbuild:devel/esbuild

USES=		go:modules
GO_MODULE=	github.com/damongolding/immich-kiosk
GO_LDFLAGS=	-X main.version=${DISTVERSION}

USE_RC_SUBR=	immich_kiosk

DBDIR=		/var/db/${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST=	DBDIR=${DBDIR}

_CHOICESJS_VER=	11.2.4
_DATEFNS_VER=	4.4.0
_HTMXSSE_VER=	2.2.4
_HTMX_VER=		2.0.11

_NODE_MODULES=	${WRKSRC}/frontend/node_modules
_ESBUILD=	${LOCALBASE}/bin/esbuild
_ESBUILD_ARGS=	--bundle --minify --log-level=warning
_ESBUILD_TARGET=	--target=chrome106,edge106,firefox107,safari12.1,opera92

USERS=		immich
GROUPS=		immich

PLIST_FILES=	bin/${PORTNAME} \
		etc/newsyslog.conf.d/immich_kiosk.conf \
		"@sample(root,immich,0640) ${ETCDIR}/config.yaml.sample" \
		"@dir(immich,immich,0750) ${DBDIR}"

post-extract:
	@${MKDIR} ${_NODE_MODULES}/choices.js ${_NODE_MODULES}/date-fns \
		${_NODE_MODULES}/htmx-ext-sse ${_NODE_MODULES}/htmx.org
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/choices.js-${_CHOICESJS_VER}.tgz \
		-C ${_NODE_MODULES}/choices.js --strip-components 1
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/date-fns-${_DATEFNS_VER}.tgz \
		-C ${_NODE_MODULES}/date-fns --strip-components 1
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/htmx-ext-sse-${_HTMXSSE_VER}.tgz \
		-C ${_NODE_MODULES}/htmx-ext-sse --strip-components 1
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/htmx.org-${_HTMX_VER}.tgz \
		-C ${_NODE_MODULES}/htmx.org --strip-components 1

pre-build:
	cd ${WRKSRC}/frontend && ${_ESBUILD} ${_ESBUILD_ARGS} \
		${_ESBUILD_TARGET} \
		--loader:.css=css --external:*.woff --external:*.woff2 \
		--external:*.ttf src/css/kiosk.css \
		--outfile=./public/assets/css/kiosk.css
	cd ${WRKSRC}/frontend && ${_ESBUILD} ${_ESBUILD_ARGS} \
		--format=iife --global-name=kiosk --target=es6 \
		src/ts/kiosk.ts --outfile=./public/assets/js/kiosk.js
	cd ${WRKSRC}/frontend && ${_ESBUILD} ${_ESBUILD_ARGS} \
		--format=iife --global-name=urlBuilder --target=es6 \
		src/ts/url-builder.ts --outfile=./public/assets/js/url-builder.js
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} tool templ generate

post-patch:
	@${REINPLACE_CMD} -e '/^kiosk:/,/^[a-z]/s/^  port: 3000/  port: 3001/' \
		${WRKSRC}/config.example.yaml

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${DBDIR} \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${WRKSRC}/config.example.yaml \
		${STAGEDIR}${ETCDIR}/config.yaml.sample
	${INSTALL_DATA} ${FILESDIR}/newsyslog-immich_kiosk.conf \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/immich_kiosk.conf

.include <bsd.port.mk>
