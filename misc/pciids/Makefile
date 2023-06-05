PORTNAME=	pciids
PORTVERSION=	20230523
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

GH_ACCOUNT=	pciutils
GH_TAGNAME=	f52a641
USE_GITHUB=	yes

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/pci.ids ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
