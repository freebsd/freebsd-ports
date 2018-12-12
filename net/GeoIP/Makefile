# Created by: Yen-Ming Lee <leeym@leeym.com>
# $FreeBSD$

PORTNAME=	GeoIP
PORTVERSION=	1.6.12
PORTREVISION=	1
CATEGORIES=	net geography
MASTER_SITES=	https://github.com/maxmind/geoip-api-c/releases/download/v${PORTVERSION}/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Find the country that any IP address or hostname originates from

LICENSE=	GPLv2

USES=		libtool pathfix

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

SUB_FILES=	geoipupdate.sh pkg-message
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	DOCS
PORTDOCS=	COPYING ChangeLog LICENSE README.md

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/geoipupdate.sh ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:C|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
