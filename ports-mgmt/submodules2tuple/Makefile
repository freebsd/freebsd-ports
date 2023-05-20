PORTNAME=	submodules2tuple
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	ports-mgmt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	GH_TUPLE generator for GitHub projects with submodules
WWW=		https://github.com/ehaupt/submodules2tuple

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	ehaupt

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/submodules2tuple

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/submodules2tuple \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
