# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Structures_DataGrid_DataSource_XML
PORTVERSION=	0.2.0
CATEGORIES=	textproc databases www pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	DataSource driver using XML files

BROKEN=		unfetchable

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PEARDIR}/Structures/DataGrid/DataSource/Array.php:databases/pear-Structures_DataGrid_DataSource_Array@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/Structures/DataGrid/DataSource/Array.php:databases/pear-Structures_DataGrid_DataSource_Array@${PHP_FLAVOR}

USES=		pear php
USE_PHP=	mysqli

NO_ARCH=	yes

.include <bsd.port.mk>
