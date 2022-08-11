PORTNAME=	govmomi
DISTVERSIONPREFIX=	v
DISTVERSION=	0.29.0
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	alex@i.org.ua
COMMENT=	vSphere CLI and vSphere API mock framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules
GO_MODULE=	github.com/vmware/govmomi

GO_TARGET=	./govc \
		./vcsim

PLIST_FILES=	bin/govc \
		bin/vcsim

.include <bsd.port.mk>
