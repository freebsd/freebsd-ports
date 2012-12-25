# Created by: Thomas Dreibholz <dreibh@iem.uni-due.de>
# $FreeBSD$

PORTNAME=	subnetcalc
PORTVERSION=	2.1.4
CATEGORIES=	net
MASTER_SITES=	http://www.iem.uni-due.de/~dreibh/subnetcalc/download/ \
		http://www.exp-math.uni-essen.de/~dreibh/subnetcalc/download/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	IPv4/IPv6 Subnet Calculator

LICENSE=	GPLv3

LIB_DEPENDS=	GeoIP:${PORTSDIR}/net/GeoIP

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--with-geoip=${LOCALBASE}"
USE_GMAKE=	yes

PLIST_FILES=	bin/subnetcalc
MAN1=		subnetcalc.1

.include <bsd.port.mk>
