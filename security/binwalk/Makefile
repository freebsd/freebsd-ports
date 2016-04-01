# $FreeBSD$

PORTNAME=	binwalk
PORTVERSION=	2.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	security python

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Search binary images for embedded files and executable code

LICENSE=	MIT

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	devttys0
USE_PYTHON=	autoplist distutils

RUN_DEPENDS=	7z:archivers/p7zip \
		cabextract:archivers/cabextract

.include <bsd.port.mk>
