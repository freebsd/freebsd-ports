PORTNAME=	kamal-proxy
PORTVERSION=	0.9.2
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight proxy server for Kamal
WWW=		https://kamal-deploy.org/ \
		https://github.com/basecamp/kamal-proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

USES=		go:modules

GO_MODULE=	github.com/basecamp/kamal-proxy
GO_TARGET=	./cmd/kamal-proxy

PLIST_FILES=	bin/kamal-proxy

.include <bsd.port.mk>
