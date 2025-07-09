PORTNAME=	usacloud
PORTREVISION=	5
#PORTREVISION=	Use PORTREVISION in Makefile.version instead
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-core

MAINTAINER=	nork@FreeBSD.org
COMMENT=	CLI client for SAKURA cloud
WWW=		https://docs.usacloud.jp/usacloud/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules

GO_MODULE=	github.com/sacloud/usacloud
GO_TARGET=	main.go:usacloud

PLIST_FILES=	bin/usacloud

.include "Makefile.version"
.include <bsd.port.mk>
