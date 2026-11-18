PORTNAME=	cloudquery
DISTVERSIONPREFIX=	v
DISTVERSION=	6.51.1
CATEGORIES=	net

MAINTAINER=	se@FreeBSD.org
COMMENT=	Transform cloud infrastructure into queryable SQL tables
WWW=		https://cloudquery.io/

LICENSE=	MPL20
#LICENSE=	MIT MPL-2.0-no-copyleft-exception
#LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/cloudquery/cloudquery/v6

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
