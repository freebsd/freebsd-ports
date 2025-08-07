PORTNAME=	ytt
DISTVERSIONPREFIX=	v
DISTVERSION=	0.52.0
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	YAML templating tool that works on YAML structure instead of text
WWW=		https://carvel.dev/ytt/ \
		https://github.com/carvel-dev/ytt

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules

GO_MODULE=	github.com/carvel-dev/ytt
GO_TARGET=	./cmd/ytt/

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
