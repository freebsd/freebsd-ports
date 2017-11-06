# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quantis
DISTVERSION=	v13.11.08
CATEGORIES=	security
MASTER_SITES=	http://www.idquantique.com/~download/Quantis/ \
		LOCAL/ale
PKGNAMESUFFIX=	-kmod
DISTNAME=	Quantis-${DISTVERSION}-src

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Kernel driver for Quantis PCI/PCIe random number generator

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKDIR}/Quantis-${DISTVERSION}/License.txt

BROKEN_powerpc64=	fails to compile: pcpu.h: size of array '__assert_0' is negative

USES=		kmod uidfix zip:infozip
EXTRACT_BEFORE_ARGS=	-aqo

WRKSRC=		${WRKDIR}/Quantis-${DISTVERSION}/Drivers/Unix/QuantisPci

PLIST_FILES=	${KMODDIR}/quantis.ko

.include <bsd.port.mk>
