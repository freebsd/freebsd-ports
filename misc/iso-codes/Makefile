PORTNAME=	iso-codes
PORTVERSION=	4.19.0
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lists of ISO standards, e.g. country, language, language scripts and currency names
WWW=		https://salsa.debian.org/iso-codes-team/iso-codes

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext-tools gmake python:build tar:bz2

BINARY_ALIAS=	python3=${PYTHON_VERSION}
GNU_CONFIGURE=	yes
NO_ARCH=	yes

USE_GITLAB=	yes
GL_SITE=	https://salsa.debian.org
GL_ACCOUNT=	iso-codes-team

.include <bsd.port.mk>
