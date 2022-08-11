PORTNAME=	ipcalc
PORTVERSION=	0.41
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://jodies.de/ipcalc-archive/
DIST_SUBDIR=	ipcalc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IP Calculator

LICENSE=	GPLv2

CONFLICTS_INSTALL=	gnu-ipcalc

PLIST_FILES=	bin/ipcalc
NO_BUILD=	yes
USES=		perl5 shebangfix

SHEBANG_FILES=	ipcalc
PATCH_SITES+=	${MASTER_SITES}
PATCHFILES+=	patch-queue

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
