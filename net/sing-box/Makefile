PORTNAME=	sing-box
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.9
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal proxy platform
WWW=		https://sing-box.sagernet.org \
		https://github.com/SagerNet/sing-box

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules

GO_MODULE=	github.com/sagernet/sing-box
GO_TARGET=	./cmd/sing-box

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
