PORTNAME=	cloudquery
DISTVERSIONPREFIX=	v
DISTVERSION=	0.32.0
PORTREVISION=	17
CATEGORIES=	net

MAINTAINER=	se@FreeBSD.org
COMMENT=	Transform cloud infrastructure into queryable SQL tables
WWW=		https://cloudquery.io/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.6.0:sys

GO_MODULE=	github.com/cloudquery/cloudquery

PLIST_FILES=	bin/${PORTNAME}

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
