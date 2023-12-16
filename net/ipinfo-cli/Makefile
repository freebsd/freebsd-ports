PORTNAME=	ipinfo
DISTVERSIONPREFIX=	ipinfo-
DISTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	nulldutra@proton.me
COMMENT=	Official Command Line Interface for the IPinfo API
WWW=		https://github.com/ipinfo/cli

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go:modules

USE_GITHUB=	yes
GH_PROJECT=	cli
GH_TUPLE=	golang:sys:v0.13.0:golang_sys

GO_TARGET=	./ipinfo

PLIST_FILES=	bin/${PORTNAME}

pre-patch:
	${RM} ${WRKSRC}/vendor/modules.txt
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
