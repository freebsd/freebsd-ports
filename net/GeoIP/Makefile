# Created by: Yen-Ming Lee <leeym@leeym.com>
# $FreeBSD$

PORTNAME=	GeoIP
PORTVERSION=	1.4.8
PORTREVISION=	4
CATEGORIES=	net geography
MASTER_SITES=	http://geolite.maxmind.com/download/geoip/api/c/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Find the country that any IP address or hostname originates from

CONFIGURE_ARGS=	CC="${CC}" PATH="${PATH}" \
		CFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

GNU_CONFIGURE=	yes
USES=		libtool:oldver
USE_LDCONFIG=	yes

SUB_FILES=	geoipupdate.sh

run-autotools:
	@${REINPLACE_CMD} -e '/^LIBTOOL=/s^\$$(top_builddir)/libtool^${LIBTOOL}^g' \
	${WRKSRC}/aclocal.m4

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/geoipupdate.sh ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
