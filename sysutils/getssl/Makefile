PORTNAME=		getssl
DISTVERSIONPREFIX=	v
DISTVERSION=		2.22
CATEGORIES=		sysutils

MAINTAINER=		rainbow@sanitylinux.org
COMMENT=		Local LetsEncrypt client for managing certificates on remote servers

LICENSE=		GPLv3
LICENSE_FILE=		${WRKSRC}/LICENSE

RUN_DEPENDS=		bash:shells/bash nslookup:dns/bind-tools curl:ftp/curl

USE_GITHUB=		yes
GH_ACCOUNT=		srvrco

NO_BUILD=		yes
NO_ARCH=		yes
PLIST_FILES=		bin/getssl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/getssl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
