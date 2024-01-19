PORTNAME=	shiori
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0-rc.6
PORTREVISION=	0
CATEGORIES=	www

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Simple bookmark manager built with Go
WWW=		https://github.com/go-shiori/shiori

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.21,modules

GO_MODULE=	github.com/go-shiori/shiori

PLIST_FILES=	bin/${PORTNAME}

BUILD_DATE=	%FT%T

# fix `shiori version` output
post-patch:
	${REINPLACE_CMD} \
		-e 's/"dev"/"${DISTVERSION}"/1' \
		-e 's/"none"/"${OPSYS}"/1' \
		-e 's/"unknown"/"${BUILD_DATE:gmtime}"/1' \
		${WRKSRC}/main.go \
		${WRKSRC}/internal/model/main.go

.include <bsd.port.mk>
