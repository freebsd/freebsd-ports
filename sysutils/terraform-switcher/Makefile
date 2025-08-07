PORTNAME=	terraform-switcher
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.5
PORTREVISION=	4
CATEGORIES=	sysutils

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Tool to switch between different versions of terraform
WWW=		https://tfswitch.warrensbox.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go:1.24,modules

GO_MODULE=	github.com/warrensbox/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-X main.version=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
