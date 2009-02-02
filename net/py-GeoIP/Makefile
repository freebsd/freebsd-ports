# New ports collection makefile for:	py-GeoIP
# Date created:		27 February 2004
# Whom:			Stefan Walter <sw@gegenunendlich.de>
#
# $FreeBSD$
#

PORTNAME=	GeoIP
PORTVERSION=	1.2.4
CATEGORIES=	net python geography
MASTER_SITES=	http://geolite.maxmind.com/download/geoip/api/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-Python-${PORTVERSION}

MAINTAINER=	stefan@FreeBSD.org
COMMENT=	Mapping of IP addresses/hostnames to country names in Python

LIB_DEPENDS=	GeoIP.5:${PORTSDIR}/net/GeoIP

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
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

.if !defined(NOPORTEXAMPLES)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
