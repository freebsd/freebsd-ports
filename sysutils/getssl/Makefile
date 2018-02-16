# $FreeBSD$

PORTNAME=		getssl
DISTVERSIONPREFIX=	v
DISTVERSION=		2.10
CATEGORIES=		sysutils

MAINTAINER=		rainbow@sanitylinux.org
COMMENT=		Local LetsEncrypt client for managing certificates on remote servers

LICENSE=		GPLv3
LICENSE_FILE=		${WRKSRC}/LICENSE

RUN_DEPENDS=            bash:shells/bash

PLIST_FILES=		bin/getssl
USE_GITHUB=		yes
GH_ACCOUNT=		srvrco
NO_BUILD=		yes
NO_ARCH=		yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/getssl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
