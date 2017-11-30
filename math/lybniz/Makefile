# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lybniz
PORTVERSION=	1.3.2
PORTREVISION=	6
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}2/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mathematical function graph plotter

LICENSE=	BSD3CLAUSE

USES=		python:2.7
USE_PYTHON=	distutils
USE_GNOME=	pygtk2

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g'\
		${WRKSRC}/${PORTNAME}.py

.include <bsd.port.mk>
