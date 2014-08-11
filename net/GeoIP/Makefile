# Created by: Yen-Ming Lee <leeym@leeym.com>
# $FreeBSD$

PORTNAME=	GeoIP
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	net geography
MASTER_SITES=	http://geolite.maxmind.com/download/geoip/api/c/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Find the country that any IP address or hostname originates from

USES=		libtool pathfix
USE_AUTOTOOLS=	aclocal automake libtoolize autoconf
AUTOMAKE_ARGS=	--add-missing
PATHFIX_MAKEFILEIN=	Makefile.am

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

SUB_FILES=	geoipupdate.sh pkg-message

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/geoipupdate.sh ${STAGEDIR}${PREFIX}/bin
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libGeoIP.so.*
	@${MKDIR} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
