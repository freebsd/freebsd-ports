PORTNAME=	bosh-bootloader
PORTVERSION=	7.6.0
PORTREVISION=	31
CATEGORIES=	net sysutils

MAINTAINER=	dumbbell@FreeBSD.org
COMMENT=	CLI for standing up CloudFoundry or Concourse on an IAAS
WWW=		https://github.com/cloudfoundry/bosh-bootloader

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_TUPLE=	cloudfoundry:bosh-bootloader:v${PORTVERSION} \
		golang:sys:v0.6.0:sys

USES=		go tar:xz

GO_PKGNAME=	github.com/cloudfoundry/bosh-bootloader
GO_TARGET=	github.com/cloudfoundry/bosh-bootloader/bbl

PLIST_FILES=	bin/bbl

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

post-patch:
	${REINPLACE_CMD} -E -e 's|(Version = )"dev"|\1"${PORTVERSION}"|' ${WRKSRC}/bbl/main.go

.include <bsd.port.mk>
