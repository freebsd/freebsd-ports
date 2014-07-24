# Created by: Yen-Ming Lee <leeym@leeym.com>
# $FreeBSD$

PORTNAME=	GeoIP
PORTVERSION=	1.4.8
PORTREVISION=	7
CATEGORIES=	net geography
MASTER_SITES=	http://geolite.maxmind.com/download/geoip/api/c/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Find the country that any IP address or hostname originates from

GNU_CONFIGURE=	yes
USES=		libtool:oldver
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal automake libtoolize autoconf
AUTOMAKE_ARGS=	--add-missing

SUB_FILES=	geoipupdate.sh pkg-message

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/geoipupdate.sh ${STAGEDIR}${PREFIX}/bin
	${MV} ${STAGEDIR}${DATADIR}/GeoIP.dat \
		${STAGEDIR}${DATADIR}/GeoIP.dat.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/GeoIP.conf.default \
		${STAGEDIR}${PREFIX}/etc/GeoIP.conf.sample
	${RM} ${STAGEDIR}${PREFIX}/etc/GeoIP.conf

.include <bsd.port.mk>
