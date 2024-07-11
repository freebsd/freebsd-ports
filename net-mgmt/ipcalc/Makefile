PORTNAME=	ipcalc
PORTVERSION=	0.51
CATEGORIES=	net-mgmt

MAINTAINER=	DtxdF@disroot.org
COMMENT=	IP Calculator
WWW=		https://jodies.de/ipcalc

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license

USES=		perl5 shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	kjokjo

SHEBANG_FILES=	ipcalc

CONFLICTS_INSTALL=	gnu-ipcalc

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/ipcalc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
