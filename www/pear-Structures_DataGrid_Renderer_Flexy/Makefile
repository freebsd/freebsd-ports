# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	Structures_DataGrid_Renderer_Flexy
PORTVERSION=	0.1.3
CATEGORIES=	www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Renderer for pear-Structures_DataGrid using HTML_Template_Flexy

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/Structures/DataGrid.php:${PORTSDIR}/devel/pear-Structures_DataGrid \
		${PEARDIR}/HTML/Template/Flexy.php:${PORTSDIR}/devel/pear-HTML_Template_Flexy \
		${PEARDIR}/Structures/DataGrid/Renderer/Pager.php:${PORTSDIR}/www/pear-Structures_DataGrid_Renderer_Pager

CATEGORY=	Structures
FILES=		DataGrid/Renderer/Flexy.php

EXAMPLES=	index.php templates/main.html templates/static_list.html \
		templates/dynamic_list.html templates/custom_results_list.html \
		templates/custom_results_default_list.html \
		templates/custom_results_noargs_list.html templates/custom_results_args_list.html

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
