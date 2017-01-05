# Created by: adamw
# $FreeBSD$

PORTNAME=	geoipupdate
PORTVERSION=	2.3.0
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
	${REINPLACE_CMD} -e '/^doc_DATA =/s|conf/GeoIP.conf.default||' \
		${WRKSRC}/Makefile.am
	${REINPLACE_CMD} -e '/DEFAULT_CONFIG_FILE =/s/GeoIP.conf$$/&.sample/' \
		${WRKSRC}/conf/Makefile.am

.include <bsd.port.mk>
