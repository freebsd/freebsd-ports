# Created by: Yen-Ming Lee <leeym@leeym.com>
# $FreeBSD$

PORTNAME=	GeoIP
PORTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	net geography

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Find the country that any IP address or hostname originates from

USE_GITHUB=	yes
GH_ACCOUNT=	maxmind
GH_PROJECT=	geoip-api-c
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	2e9100a

USES=		libtool pathfix
USE_AUTOTOOLS=	aclocal automake libtoolize autoconf
AUTOMAKE_ARGS=	--add-missing
PATHFIX_MAKEFILEIN=	Makefile.am

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

SUB_FILES=	geoipupdate.sh pkg-message

OPTIONS_DEFINE=	DOCS
PORTDOCS=	COPYING ChangeLog LICENSE README.md

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/geoipupdate.sh ${STAGEDIR}${PREFIX}/bin
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libGeoIP.so.*
	@${MKDIR} ${STAGEDIR}${DATADIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
