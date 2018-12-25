# Created by: Thomas Dreibholz <dreibh@iem.uni-due.de>
# $FreeBSD$

PORTNAME=	subnetcalc
DISTVERSION=	2.4.9
CATEGORIES=	net
MASTER_SITES=	https://www.uni-due.de/~be0001/subnetcalc/download/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	IPv4/IPv6 Subnet Calculator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libGeoIP.so:net/GeoIP

USES=		cmake
CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR:PATH="man"

PLIST_FILES=	bin/subnetcalc \
		man/man1/subnetcalc.1.gz

.include <bsd.port.mk>
