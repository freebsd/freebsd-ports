PORTNAME=	neofetch
DISTVERSION=	7.1.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Fast, highly customizable system info script

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	dylanaraps

NO_ARCH=	yes
NO_BUILD=	yes

MAKE_ENV=	PREFIX="${PREFIX}"

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
