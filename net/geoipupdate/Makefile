# Created by: adamw
# $FreeBSD$

PORTNAME=	geoipupdate
PORTVERSION=	2.5.0
CATEGORIES=	net geography
MASTER_SITES=	https://github.com/maxmind/geoipupdate/releases/download/v${PORTVERSION}/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Fetch the latest copies of the paid GeoIP database

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		libtool localbase pathfix
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/GeoIP
	${MV} ${STAGEDIR}${DOCSDIR}/GeoIP.conf.default \
		${STAGEDIR}${PREFIX}/etc/GeoIP.conf.sample

.include <bsd.port.mk>
