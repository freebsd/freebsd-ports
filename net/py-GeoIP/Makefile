# Created by: Stefan Walter <sw@gegenunendlich.de>
# $FreeBSD$

PORTNAME=	GeoIP
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	net python geography
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Mapping of IP addresses/hostnames to country names in Python

LICENSE=	GPLv2

LIB_DEPENDS=	libGeoIP.so:net/GeoIP

OPTIONS_DEFINE=	EXAMPLES

USE_PYTHON=	autoplist concurrent distutils
USES=		localbase python shebangfix

PORTEXAMPLES=	*

SHEBANG_FILES=	examples/*.py

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/examples/*.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/GeoIP.so

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/examples/ && ${INSTALL_DATA} *.py ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
