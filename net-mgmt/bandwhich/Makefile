PORTNAME=	bandwhich
DISTVERSIONPREFIX=	v
DISTVERSION=	0.23.1
PORTREVISION=	8
CATEGORIES=	net-mgmt

MAINTAINER=	petteri.valkonen@iki.fi
COMMENT=	Terminal bandwidth utilization tool
WWW=		https://github.com/imsnif/bandwhich

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	lsof:sysutils/lsof

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	imsnif

PLIST_FILES=	bin/bandwhich

.include <bsd.port.mk>
