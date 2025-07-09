PORTNAME=	gomuks
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
PORTREVISION=	6
CATEGORIES=	net-im

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Terminal Matrix client written in Go
WWW=		https://github.com/tulir/gomuks

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libolm.so:security/olm

USES=		go:modules

GO_MODULE=	github.com/tulir/gomuks

PLIST_FILES=	bin/gomuks

.include <bsd.port.mk>
