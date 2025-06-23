PORTNAME=	hugo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.147.9
PORTEPOCH=	1
CATEGORIES=	www
PKGNAMEPREFIX=	go
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Fast and Flexible Static Site Generator built with love in GoLang
WWW=		https://gohugo.io

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	gohugo

GO_MODULE=	github.com/gohugoio/hugo
GO_BUILDFLAGS=	-ldflags="\
		${STRIP} -w \
		-X github.com/gohugoio/hugo/common/hugo.buildDate=${SOURCE_DATE_EPOCH:U${SOURCE_DATE_EPOCH_CMD:sh}} \
		-X github.com/gohugoio/hugo/common/hugo.vendorInfo=freebsd" \
		${BUILD_TAGS}

CONFLICTS_INSTALL=	hugo # bin/hugo

OPTIONS_DEFINE=		MANPAGES EXTENDED
OPTIONS_DEFAULT=	MANPAGES EXTENDED
OPTIONS_SUB=		yes

EXTENDED_DESC=		Enable SCSS/SASS support

EXTENDED_LIB_DEPENDS=	libsass.so:textproc/libsass \
			libwebp.so:graphics/webp
EXTENDED_VARS=		CGO_ENABLED=1 \
			CGO_CFLAGS="-DLIBWEBP_NO_SRC -DUSE_LIBSASS_SRC" \
			CGO_LDFLAGS="-lm -lwebp -lsass" \
			BUILD_TAGS="-tags extended"
EXTENDED_VARS_OFF=	CGO_ENABLED=0

PORTMANS=	hugo-completion-bash.1 hugo-completion-fish.1 hugo-completion-powershell.1 \
		hugo-completion-zsh.1 hugo-completion.1 hugo-config-mounts.1 \
		hugo-config.1 hugo-convert-toJSON.1 hugo-convert-toTOML.1 hugo-convert-toYAML.1 \
		hugo-convert.1 hugo-env.1 hugo-gen-chromastyles.1 hugo-gen-doc.1 \
		hugo-gen-man.1 hugo-gen.1 hugo-import-jekyll.1 hugo-import.1 hugo-list-all.1 \
		hugo-list-drafts.1 hugo-list-expired.1 hugo-list-future.1 hugo-list.1 \
		hugo-mod-clean.1 hugo-mod-get.1 hugo-mod-graph.1 hugo-mod-init.1 \
		hugo-mod-npm-pack.1 hugo-mod-npm.1 hugo-mod-tidy.1 hugo-mod-vendor.1 \
		hugo-mod-verify.1 hugo-mod.1 hugo-new-site.1 hugo-new-theme.1 hugo-new.1 \
		hugo-server.1 hugo-version.1 hugo.1

# needed to get DISTINFO_FILE in scope for the shell command evaluation by go.mk
.include <bsd.port.pre.mk>

SOURCE_DATE_EPOCH_CMD=	date -r $$(grep TIMESTAMP ${DISTINFO_FILE} | ${SED} -e 's/[^0-9]//g') '+%FT%TZ%z'

do-build-MANPAGES-on:
	@cd ${GO_WRKSRC} && ${GO_WRKDIR_BIN}/${PORTNAME} gen man --dir man/man1/

do-install-MANPAGES-on:
.for i in ${PORTMANS}
	${INSTALL_MAN} ${WRKSRC}/man/man1/$i ${STAGEDIR}/${PREFIX}/share/man/man1
.endfor

.include <bsd.port.post.mk>
