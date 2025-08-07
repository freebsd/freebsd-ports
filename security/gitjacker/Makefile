PORTNAME=	gitjacker
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
PORTREVISION=	29
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Leak git repositories from misconfigured websites
WWW=		https://github.com/liamg/gitjacker

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.6.0:sys

CPE_VENDOR=	${PORTNAME}_project

GO_MODULE=	github.com/liamg/gitjacker
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
