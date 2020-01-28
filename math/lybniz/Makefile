# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lybniz
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.4-2
DISTVERSIONSUFFIX=	-gf1ec282
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Mathematical function graph plotter

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Old, uses EOLed python27
EXPIRATION_DATE=	2020-03-01

USES=		gnome python
USE_GITHUB=	yes
GH_ACCOUNT=	thomasfuhringer
USE_PYTHON=	distutils noflavors autoplist
USE_GNOME=	pygtk2

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g'\
		${WRKSRC}/${PORTNAME}.py

.include <bsd.port.mk>
