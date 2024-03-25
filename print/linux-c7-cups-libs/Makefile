PORTNAME=	cups-libs
PORTVERSION=	1.6.3
DISTVERSIONSUFFIX=	-52.el7_9
PORTREVISION=	10
CATEGORIES=	print linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Common UNIX Printing System libraries
WWW=		https://github.com/OpenPrinting/cups

USES=		cpe linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	avahi-libs
USE_LINUX_RPM=	yes

SRC_DISTFILES=	cups-${DISTVERSIONFULL}${SRC_SUFX}:SOURCE

DESCR=		${.CURDIR}/../cups/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
