# Created by: Stefan Walter <sw@gegenunendlich.de>
# $FreeBSD$

PORTNAME=	GeoIP
PORTVERSION=	1.2.8
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net python geography
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Mapping of IP addresses/hostnames to country names in Python

LICENSE=	GPLv2

LIB_DEPENDS=	libGeoIP.so:${PORTSDIR}/net/GeoIP

USE_GITHUB=	yes
GH_ACCOUNT=	maxmind
GH_PROJECT=	geoip-api-python

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	GeoIP-Python

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
EXAMPLE_FILES=	README test.py test_city.py test_org.py test_region.py

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/GeoIP.so
PORTEXAMPLES=	README test.py test_city.py test_org.py test_region.py

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/setup.py \
		${WRKSRC}/test.py \
		${WRKSRC}/test_city.py \
		${WRKSRC}/test_org.py \
		${WRKSRC}/test_region.py

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for file in ${EXAMPLE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
