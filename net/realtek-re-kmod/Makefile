PORTNAME=	re
PORTVERSION=	196.04
DISTVERSIONPREFIX=	v
CATEGORIES=	net
MASTER_SITES=	LOCAL/ale
PKGNAMEPREFIX=	realtek-
PKGNAMESUFFIX=	-kmod
DISTNAME=	rtl_bsd_drv_${DISTVERSIONPREFIX}${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Kernel driver for Realtek PCIe Ethernet Controllers
WWW=		https://www.realtek.com/en/component/zoo/category/network-interface-controllers-10-100-1000m-gigabit-ethernet-pci-express-software

LICENSE=	BSD4CLAUSE

USES=		kmod tar:tgz uidfix

PLIST_FILES=	${KMODDIR}/if_re.ko

.include <bsd.port.mk>
