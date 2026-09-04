PORTNAME=	xray
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	textproc

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Read-only profiler for tabular data
WWW=		https://excelano.com/xray/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	excelano

CONFLICTS_INSTALL=	xray-core

PLIST_FILES=	bin/xray

.include <bsd.port.mk>
