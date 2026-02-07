PORTNAME=	quantis
DISTVERSION=	v18.03.08
CATEGORIES=	security
MASTER_SITES=	https://www.idquantique.com/wordpress/wp-content/uploads/
PKGNAMESUFFIX=	-kmod
DISTNAME=	Quantis-${DISTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Kernel driver for Quantis PCI/PCIe random number generator
WWW=		https://www.idquantique.com/

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKDIR}/Quantis-${DISTVERSION}/License.txt

USES=		kmod uidfix zip

WRKSRC=		${WRKDIR}/Quantis-${DISTVERSION}/Drivers/Unix/QuantisPci

PLIST_FILES=	${KMODDIR}/quantis.ko

.include <bsd.port.mk>
