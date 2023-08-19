PORTNAME=	cups
PORTVERSION=	2.3.3
DISTVERSIONSUFFIX=	op2-21.el9
PORTREVISION=	2
CATEGORIES=	print linux
PKGNAMESUFFIX=	-libs

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Common UNIX Printing System libraries
WWW=		https://github.com/OpenPrinting/cups

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	avahi-libs libidn2
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}

CONFLICTS=	linux-c6-${PORTNAME}${PKGNAMESUFFIX} linux-c7-${PORTNAME}${PKGNAMESUFFIX}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
