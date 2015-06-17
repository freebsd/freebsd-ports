# Created by: Stefan Walter <sw@gegenunendlich.de>
# $FreeBSD$

PORTNAME=	GeoIP
PORTVERSION=	1.3.2
CATEGORIES=	net python geography
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Mapping of IP addresses/hostnames to country names in Python

LICENSE=	GPLv2

LIB_DEPENDS=	libGeoIP.so:${PORTSDIR}/net/GeoIP

CPPFLAGS+=	-I${LOCALBASE}/include
USE_PYTHON=	autoplist distutils
USES=		python shebangfix

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
PORTEXAMPLES=	*

SHEBANG_FILES=	examples/*.py

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/examples/*.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/GeoIP.so
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/examples/ && ${INSTALL_DATA} *.py ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
