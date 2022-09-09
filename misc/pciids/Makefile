PORTNAME=	pciids
PORTVERSION=	20220807
CATEGORIES=	misc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Database of all known IDs used in PCI devices
WWW=		https://github.com/pciutils/pciids

LICENSE=	BSD3CLAUSE GPLv2+
LICENSE_COMB=	dual

NO_ARCH=	yes
NO_BUILD=	yes

PORTDATA=	pci.ids

GH_ACCOUNT=	pciutils
GH_TAGNAME=	2c1f486
USE_GITHUB=	yes

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/pci.ids ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
