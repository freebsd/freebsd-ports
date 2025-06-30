PORTNAME=	pciids
PORTVERSION=	20250621
CATEGORIES=	misc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Database of all known IDs used in PCI devices
WWW=		https://pci-ids.ucw.cz/ \
		https://github.com/pciutils/pciids

LICENSE=	BSD3CLAUSE GPLv2+
LICENSE_COMB=	dual

NO_ARCH=	yes
NO_BUILD=	yes

PORTDATA=	pci.ids

USE_GITHUB=	yes
GH_ACCOUNT=	pciutils
GH_TAGNAME=	6d8349f

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/pci.ids ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
