PORTNAME=	nerdctl
DISTVERSIONPREFIX=v
DISTVERSION=	2.1.3
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	laurent.chardon@gmail.com
COMMENT=	Docker-compatible CLI for containerd
WWW=		https://github.com/containerd/nerdctl

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules

USE_GITHUB=	yes
GH_ACCOUNT=	containerd
GH_PROJECT=	${PORTNAME}
GO_MOD_DIST=	github

GO_MODULE=	github.com/containerd/nerdctl/v2
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "-s -w -X ${GO_MODULE}/pkg/version.Version=${DISTVERSIONFULL}"

PLIST_FILES=	bin/containerd-rootless.sh \
		bin/containerd-rootless-setuptool.sh \
		bin/nerdctl \
		etc/bash_completion.d/${PORTNAME} \
		share/fish/vendor_completions.d/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

pre-fetch:
	@${MKDIR} ${DISTDIR}/${DIST_SUBDIR}
	[ -e ${DISTDIR}/${DIST_SUBDIR}/go.mod ] || \
		(${FETCH_CMD} ${FETCH_BEFORE_ARGS} \
			https://raw.githubusercontent.com/containerd/nerdctl/v2.1.3/go.mod \
			-o ${DISTDIR}/${DIST_SUBDIR}/go.mod; \
		${REINPLACE_CMD} '/tigron/d' ${DISTDIR}/${DIST_SUBDIR}/go.mod)

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/extras/rootless/* ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	@${MKDIR} ${WRKDIR}/tmp
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} --data-root=${WRKDIR}/tmp completion bash > ${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} --data-root=${WRKDIR}/tmp completion fish > ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/${PORTNAME}.fish
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} --data-root=${WRKDIR}/tmp completion zsh  > ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
