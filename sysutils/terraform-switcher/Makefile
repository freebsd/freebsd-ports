PORTNAME=	terraform-switcher
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2
CATEGORIES=	sysutils

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Tool to switch between different versions of terraform
WWW=		https://tfswitch.warrensbox.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go:1.22,modules

GO_MODULE=	github.com/warrensbox/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-X main.version=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
