PORTNAME=	cups
PORTVERSION=	2.3.3
DISTVERSIONSUFFIX=	op2-31.el9_5
PORTREVISION=	6
CATEGORIES=	print linux
PKGNAMESUFFIX=	-libs

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Common UNIX Printing System libraries
WWW=		https://github.com/OpenPrinting/cups

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	avahi-libs gnutls libidn2
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}

CONFLICTS=	linux-c7-${PORTNAME}${PKGNAMESUFFIX}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr

.include <bsd.port.mk>
