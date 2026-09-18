PORTNAME=	immich-go
DISTVERSIONPREFIX=	v
DISTVERSION=	0.32.0
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Command line tool to bulk upload photos and videos to Immich
WWW=		https://github.com/simulot/immich-go

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/simulot/immich-go

GO_LDFLAGS=	-X ${GO_MODULE}/app.Version=${DISTVERSION}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
