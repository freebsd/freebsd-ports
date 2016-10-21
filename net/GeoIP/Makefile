# Created by: Yen-Ming Lee <leeym@leeym.com>
# $FreeBSD$

PORTNAME=	GeoIP
PORTVERSION=	1.6.9
DISTVERSIONPREFIX=	v
CATEGORIES=	net geography

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Find the country that any IP address or hostname originates from

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	maxmind
GH_PROJECT=	geoip-api-c

USES=		autoreconf libtool pathfix

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

SUB_FILES=	geoipupdate.sh pkg-message
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	DOCS
PORTDOCS=	COPYING ChangeLog LICENSE README.md

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/geoipupdate.sh ${STAGEDIR}${PREFIX}/bin
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libGeoIP.so.*
	@${MKDIR} ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
