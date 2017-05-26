# Created by: adamw
# $FreeBSD$

PORTNAME=	geoipupdate
PORTVERSION=	2.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net geography

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Fetch the latest copies of the paid GeoIP database

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	maxmind

USES=		libtool localbase pathfix autoreconf
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
# This directory is handled by net/GeoIP
	@${REINPLACE_CMD} -e '/MKDIR_P.*(datarootdir)\/GeoIP/ d' \
		${WRKSRC}/Makefile.am

post-install:
	${MV} ${STAGEDIR}${DOCSDIR}/GeoIP.conf.default \
		${STAGEDIR}${PREFIX}/etc/GeoIP.conf.sample

.include <bsd.port.mk>
