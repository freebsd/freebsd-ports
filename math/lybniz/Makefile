# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lybniz
PORTVERSION=	1.3.2
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}2/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mathematical function graph plotter

USE_PYTHON=	yes
USE_GNOME=	pygtk2 gnomehier
USE_PYDISTUTILS=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g'\
		${WRKSRC}/${PORTNAME}.py

.include <bsd.port.mk>
