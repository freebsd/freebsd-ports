PORTNAME=	mkbrr
DISTVERSIONPREFIX=	v
DISTVERSION=	1.14.0
CATEGORIES=	net-p2p

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	Commmand-line utility to create, modify and inspect torrent files written in Go
WWW=		https://github.com/autobrr/mkbrr

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules

CGO_ENABLED=	0
GO_MODULE=	github.com/autobrr/${PORTNAME}

PLIST_FILES=	bin/mkbrr

post-patch:
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|g' \
	    ${PATCH_WRKSRC}/main.go
	@${REINPLACE_CMD} -e 's|%%BUILDTIME%%|${CONFIGURE_TARGET}|g' \
	    ${PATCH_WRKSRC}/main.go
	${RM} ${PATCH_WRKSRC}/cmd/update.go

.include <bsd.port.mk>
