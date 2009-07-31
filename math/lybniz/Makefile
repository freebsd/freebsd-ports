# New ports collection makefile for:	lybniz
# Date created:		3 November 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lybniz
PORTVERSION=	1.3.2
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mathematical function graph plotter

USE_PYTHON=	yes
USE_GNOME=	pygtk2 gnomehier
USE_PYDISTUTILS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g'\
		${WRKSRC}/${PORTNAME}.py

.include <bsd.port.mk>
