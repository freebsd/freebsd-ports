# New ports collection makefile for:	GeoIP
# Date created:				10 August 2002
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	GeoIP
PORTVERSION=	1.4.8
PORTREVISION=	1
CATEGORIES=	net geography
MASTER_SITES=	http://geolite.maxmind.com/download/geoip/api/c/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Find the country that any IP address or hostname originates from

CONFIGURE_ARGS=	CC="${CC}" PATH="${PATH}" \
			CFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
WITH_FBSD10_FIX=yes

MAN1=		geoiplookup.1 geoipupdate.1 geoiplookup6.1

run-autotools:
	@${REINPLACE_CMD} -e '/^LIBTOOL=/s^\$$(top_builddir)/libtool^${LIBTOOL}^g' \
	${WRKSRC}/aclocal.m4

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/geoipupdate.sh ${PREFIX}/bin/

.include <bsd.port.mk>
