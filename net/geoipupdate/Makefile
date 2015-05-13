# Created by: adamw
# $FreeBSD$

PORTNAME=	geoipupdate
PORTVERSION=	2.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net geography

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Fetch the latest copies of the paid GeoIP database

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	maxmind

USES=		libtool pathfix autoreconf
PATHFIX_MAKEFILEIN=	Makefile.am
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-extract:
	@${MV} ${WRKSRC}/conf/GeoIP.conf.default ${WRKSRC}/conf/GeoIP.conf.sample

post-patch:
	@${REINPLACE_CMD} -e '/^DEFAULT_CONFIG_FILE =/s/$$/.sample/' \
		-e 's/.default/.sample/' \
		${WRKSRC}/conf/Makefile.am

.include <bsd.port.mk>
