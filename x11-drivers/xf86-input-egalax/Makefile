PORTNAME=	xf86-input-egalax
PORTVERSION=	0.3
PORTREVISION=	7
CATEGORIES=	x11-drivers

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	eGalax touch screen input driver for X.Org

LICENSE=	BSD2CLAUSE

FLAVORS=	xorg xlibre
FLAVOR?=	${FLAVORS:[1]}

.if ${FLAVOR} == xlibre
PKGNAMEPREFIX=	xlibre-
USES=		xlibre-cat:driver
.else
USES=		xorg-cat:driver
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	glebius
GH_TAGNAME=	7f1e4ac

USES+=		autoreconf

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

.include <bsd.port.mk>
