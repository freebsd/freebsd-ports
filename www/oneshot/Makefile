PORTNAME=	oneshot
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.1
PORTREVISION=	29
CATEGORIES=	www

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	First-come-first-serve single-fire HTTP server
WWW=		https://github.com/raphaelreyna/oneshot

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:net:v0.8.0:net \
		golang:sys:v0.6.0:sys

_BUILD_VERSION=	${DISTVERSIONFULL}
_BUILD_DATE=	$$(date +%d-%B-%Y)

GO_MODULE=	github.com/raphaelreyna/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		${STRIP} -w \
		-X ${GO_MODULE}/cmd.version=${_BUILD_VERSION} \
		-X ${GO_MODULE}/cmd.date=${_BUILD_DATE}"

PORTDOCS=	README.md

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

MANPAGES_DESC=	Build and install auto-generated manpages

pre-patch:
.for m in net sys
	${RM} -r ${WRKSRC}/vendor/golang.org/x/$m
	${LN} -s ${WRKDIR}/$m-* ${WRKSRC}/vendor/golang.org/x/$m
.endfor

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
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
