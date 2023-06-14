PORTNAME=	iso-codes
PORTVERSION=	4.7
CATEGORIES=	misc

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Lists of the country, language, and currency iso names
WWW=		https://salsa.debian.org/iso-codes-team/iso-codes

LICENSE=	LGPL21

USES=		gettext-tools gmake pathfix python:build tar:xz

GNU_CONFIGURE=	yes
NO_ARCH=	yes

USE_GITLAB=	yes
GL_SITE=	https://salsa.debian.org
GL_ACCOUNT=	iso-codes-team
GL_COMMIT=	59767ed869f3952575f7d0f639a290a4c4b315e5

BINARY_ALIAS=	python3=${PYTHON_VERSION}

.include <bsd.port.mk>
