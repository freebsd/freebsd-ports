# Created by: Ting-Wei Lan <lantw44@gmail.com>
# $FreeBSD$

PORTNAME=	pnpids
PORTVERSION=	20140917
CATEGORIES=	misc

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Database of IDs used in Plug and Play devices

LICENSE=	GPLv2+ MIT
LICENSE_COMB=	dual

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${DATADIR}/pnp.ids

USE_GITHUB=	yes
GH_ACCOUNT=	vcrhonek
GH_PROJECT=	hwdata
GH_TAGNAME=	v0.308

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/pnp.ids ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
