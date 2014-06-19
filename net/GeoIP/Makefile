# Created by: Yen-Ming Lee <leeym@leeym.com>
# $FreeBSD$

PORTNAME=		GeoIP
PORTVERSION=	1.4.8
PORTREVISION=	5
CATEGORIES=		net geography
MASTER_SITES=	http://geolite.maxmind.com/download/geoip/api/c/

MAINTAINER=		adamw@FreeBSD.org
COMMENT=		Find the country that any IP address or hostname originates from

GNU_CONFIGURE=	yes
USES=			libtool:oldver
USE_LDCONFIG=	yes

SUB_FILES=		geoipupdate.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/geoipupdate.sh ${STAGEDIR}${PREFIX}/bin
	${MV} ${STAGEDIR}${DATADIR}/GeoIP.dat \
		${STAGEDIR}${DATADIR}/GeoIP.dat.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/GeoIP.conf.default \
		${STAGEDIR}${PREFIX}/etc/GeoIP.conf.sample
	${RM} ${STAGEDIR}${PREFIX}/etc/GeoIP.conf

.include <bsd.port.mk>
