# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iso-codes
PORTVERSION=	4.1
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Lists of the country, language, and currency iso names

LICENSE=	LGPL21

USES=		gettext-tools gmake pathfix python:3.4+,build tar:xz

GNU_CONFIGURE=	yes
NO_ARCH=	yes

USE_GITLAB=	yes
GL_SITE=	https://salsa.debian.org
GL_ACCOUNT=	iso-codes-team
GL_COMMIT=	164802d5fd8c7a8167816fd86a62b286680619f0

BINARY_ALIAS=	python3=${PYTHON_VERSION}

.include <bsd.port.mk>
