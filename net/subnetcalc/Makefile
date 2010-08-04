# New ports collection makefile for: subnetcalc
# Date created:                      27 July 2010
# Whom:                              Thomas Dreibholz <dreibh@iem.uni-due.de>
#
# $FreeBSD$
#

PORTNAME=	subnetcalc
PORTVERSION=	2.1.2
CATEGORIES=	net
MASTER_SITES=	http://www.iem.uni-due.de/~dreibh/subnetcalc/download/ \
		http://www.exp-math.uni-essen.de/~dreibh/subnetcalc/download/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	IPv4/IPv6 Subnet Calculator

LIB_DEPENDS=	GeoIP.5:${PORTSDIR}/net/GeoIP

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--with-geoip=${LOCALBASE}"
USE_GMAKE=	yes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

PLIST_FILES=	bin/subnetcalc
MAN8=		subnetcalc.8

.include <bsd.port.mk>
