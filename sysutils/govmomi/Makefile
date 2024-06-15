PORTNAME=	govmomi
DISTVERSIONPREFIX=	v
DISTVERSION=	0.36.2
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	alex@i.org.ua
COMMENT=	Go library for the VMware vSphere API
WWW=		https://github.com/vmware/govmomi/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules
GO_MODULE=	github.com/vmware/govmomi

GO_TARGET=	./govc \
		./vcsim

PLIST_FILES=	bin/govc \
		bin/vcsim

.include <bsd.port.mk>
