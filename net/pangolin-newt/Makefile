PORTNAME=	pangolin-newt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.18.1
CATEGORIES=	net

MAINTAINER=	soehnke.dencker@sh4u.de
COMMENT=	Tunneled network connector for Pangolin
WWW=		https://github.com/fosrl/newt

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26+,modules

GO_MODULE=	github.com/fosrl/newt
GO_TARGET=	.:${PREFIX}/sbin/newt
GO_LDFLAGS=	-X main.newtVersion=${DISTVERSION}
CGO_ENABLED=	0

PLIST_FILES=	sbin/newt

.include <bsd.port.mk>
