# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Structures_DataGrid_DataSource_RSS
PORTVERSION=	0.1.1
CATEGORIES=	textproc databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	DataSource driver using RSS files

BROKEN=		unfetchable

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PEARDIR}/Structures/DataGrid/DataSource/Array.php:databases/pear-Structures_DataGrid_DataSource_Array@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/Structures/DataGrid/DataSource/Array.php:databases/pear-Structures_DataGrid_DataSource_Array@${PHP_FLAVOR}

USES=		pear php
USE_PHP=	mysqli

NO_ARCH=	yes

.include <bsd.port.mk>
