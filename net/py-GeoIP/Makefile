# New ports collection makefile for:	py-GeoIP
# Date created:		27 February 2004
# Whom:			Stefan Walter <sw@gegenunendlich.de>
#
# $FreeBSD$
#

PORTNAME=	GeoIP
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-Python-${PORTVERSION}

MAINTAINER=	sw@gegenunendlich.de
COMMENT=	Mapping of IP addresses/hostnames to country names in Python

LIB_DEPENDS=	GeoIP.4:${PORTSDIR}/net/GeoIP

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLE_FILES=	README test.py test_city.py test_org.py

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/GeoIP.so \
		%%PORTDOCS%%%%EXAMPLESDIR%%/README \
		%%PORTDOCS%%%%EXAMPLESDIR%%/test.py \
		%%PORTDOCS%%%%EXAMPLESDIR%%/test_city.py \
		%%PORTDOCS%%%%EXAMPLESDIR%%/test_org.py
PLIST_DIRS=	%%PORTDOCS%%%%EXAMPLESDIR%%

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
