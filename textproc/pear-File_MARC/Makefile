# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	File_MARC
PORTVERSION=	1.4.1
CATEGORIES=	textproc pear

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Parse, modify, and create MARC records

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	pear
NO_ARCH=	yes

OPTIONS_DEFINE=	ISPN

ISPN_DESC=	Validation class for ISPN (International Standard Product Numbers)
ISPN_RUN_DEPENDS=	${PEARDIR}/Validate/ISPN.php:textproc/pear-Validate_ISPN@${PHP_FLAVOR}

.include <bsd.port.mk>
