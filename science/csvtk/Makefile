PORTNAME=	csvtk
DISTVERSIONPREFIX=	v
DISTVERSION=	0.33.0
PORTREVISION=	4
CATEGORIES=	science

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Cross-platform and ultrafast toolkit for CSV/TSV processing
WWW=		https://bioinf.shenwei.me/csvtk/ \
		https://github.com/shenwei356/csvtk/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.6.0:sys

GO_MODULE=	github.com/shenwei356/csvtk
GO_TARGET=	./${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
