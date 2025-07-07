PORTNAME=	iso-codes
DISTVERSIONPREFIX=	v
DISTVERSION=	4.18.0
CATEGORIES=	misc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lists of the country, language, and currency iso names
WWW=		https://salsa.debian.org/iso-codes-team/iso-codes

LICENSE=	LGPL21

USES=		gettext-tools gmake pathfix python:build tar:xz

GNU_CONFIGURE=	yes
NO_ARCH=	yes

USE_GITLAB=	yes
GL_SITE=	https://salsa.debian.org
GL_ACCOUNT=	iso-codes-team

BINARY_ALIAS=	python3=${PYTHON_VERSION}

.include <bsd.port.mk>
