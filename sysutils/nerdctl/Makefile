PORTNAME=	nerdctl
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
CATEGORIES=	sysutils
DISTFILES+=	go.mod

MAINTAINER=	laurent@FreeBSD.org
COMMENT=	Docker-compatible CLI for containerd
WWW=		https://github.com/containerd/nerdctl

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26+,modules
USE_GITHUB=	yes
GH_ACCOUNT=	containerd

GO_MODULE=	github.com/containerd/nerdctl/v2
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "-s -w -X ${GO_MODULE}/pkg/version.Version=${DISTVERSIONFULL}"
GO_TESTTARGET=	./pkg/...

PLIST_FILES=	bin/nerdctl \
		etc/bash_completion.d/${PORTNAME} \
		share/fish/vendor_completions.d/${PORTNAME}.fish \
		share/licenses/${PKGNAME}/NOTICE \
		share/zsh/site-functions/_${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-fetch:
	@${MKDIR} ${DISTDIR}/${DIST_SUBDIR}
	[ -e ${DISTDIR}/${DIST_SUBDIR}/go.mod ] || \
		(${FETCH_CMD} ${FETCH_BEFORE_ARGS} \
			https://raw.githubusercontent.com/containerd/nerdctl/v${DISTVERSION}/go.mod \
			-o ${DISTDIR}/${DIST_SUBDIR}/go.mod; \
		${REINPLACE_CMD} '/tigron/d' ${DISTDIR}/${DIST_SUBDIR}/go.mod)

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		  ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d \
		  ${STAGEDIR}${PREFIX}/share/zsh/site-functions \
		  ${STAGEDIR}${_LICENSE_DIR} \
		  ${WRKDIR}/tmp
	${INSTALL_DATA} ${WRKSRC}/NOTICE ${STAGEDIR}${_LICENSE_DIR}
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} --data-root=${WRKDIR}/tmp completion bash \
		> ${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} --data-root=${WRKDIR}/tmp completion fish \
		> ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/${PORTNAME}.fish
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} --data-root=${WRKDIR}/tmp completion zsh  \
		> ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

post-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "README.md docs" ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
