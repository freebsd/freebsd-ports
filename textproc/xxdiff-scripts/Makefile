# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xxdiff
PORTVERSION=	4.0
CATEGORIES=	textproc
MASTER_SITES=	SF
PKGNAMESUFFIX=	-scripts

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Helper scripts for xxdiff

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	xxdiff:textproc/xxdiff

USES=		python:2 tar:bzip2
USE_PYTHON=	autoplist distutils
PYDISTUTILS_PKGNAME=	xxdiff-scripts
NO_ARCH=	yes

.include <bsd.port.mk>
