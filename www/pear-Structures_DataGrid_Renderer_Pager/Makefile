# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	Structures_DataGrid_Renderer_Pager
PORTVERSION=	0.1.3
CATEGORIES=	www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pager Renderer for pear-Structures_DataGrid

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/Structures/DataGrid.php:${PORTSDIR}/devel/pear-Structures_DataGrid \
		${PEARDIR}/Pager/Pager.php:${PORTSDIR}/devel/pear-Pager

CATEGORY=	Structures
FILES=		DataGrid/Renderer/Pager.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
