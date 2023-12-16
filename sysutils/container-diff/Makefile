PORTNAME=	container-diff
PORTVERSION=	0.17.0
DISTVERSIONPREFIX=	v
PORTREVISION=	16
CATEGORIES=	sysutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Diff your Docker containers
WWW=		https://github.com/GoogleContainerTools/container-diff

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

PLIST_FILES=	bin/container-diff

USE_GITHUB=	yes
GH_TUPLE=	GoogleContainerTools:container-diff:v${PORTVERSION} \
		golang:sys:v0.6.0:sys

pre-patch:
	@${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	@${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
