PORTNAME=	librespeed-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.12
PORTREVISION=	2
CATEGORIES=	net www

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	CLI interface to run librespeed speedtests
WWW=		https://github.com/librespeed/speedtest-cli

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:net:v0.8.0:net \
		golang:sys:v0.6.0:sys

GO_MODULE=	github.com/librespeed/speedtest-cli
GO_BUILDFLAGS+=	-ldflags "-X \"librespeed-cli/defs.ProgName=${PORTNAME}\" \
		-X \"librespeed-cli/defs.ProgVersion=${PORTVERSION}-freebsd\" \
		-X \"librespeed-cli/defs.BuildDate=`date -u '+%Y-%m-%d %H:%M:%S %Z'`\""

PLIST_FILES=	bin/librespeed-cli

pre-patch:
.for m in net sys
	${RM} -r ${WRKSRC}/vendor/golang.org/x/$m
	${LN} -s ${WRKDIR}/$m-* ${WRKSRC}/vendor/golang.org/x/$m
.endfor

.include <bsd.port.mk>
