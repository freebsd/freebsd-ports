PORTNAME=	oneshot
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	First-come-first-serve single-fire HTTP server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

_BUILD_VERSION=	${DISTVERSIONFULL}
_BUILD_DATE=	$$(date +%d-%B-%Y)

GO_MODULE=	github.com/raphaelreyna/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X ${GO_MODULE}/cmd.version=${_BUILD_VERSION} \
		-X ${GO_MODULE}/cmd.date=${_BUILD_DATE}"

PORTDOCS=	README.md

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

MANPAGES_DESC=	Build and install auto-generated manpages

do-build-MANPAGES-on:
	cd ${GO_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} run ${GO_BUILDFLAGS} \
		./doc/man/main.go > ${PORTNAME}.1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${GO_WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

post-install-MANPAGES-on:
	${INSTALL_MAN} ${GO_WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
