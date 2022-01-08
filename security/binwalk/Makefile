PORTNAME=	binwalk
PORTVERSION=	2.1.1
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	security python

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Search binary images for embedded files and executable code

LICENSE=	MIT

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	devttys0
USE_PYTHON=	autoplist distutils optsuffix concurrent

RUN_DEPENDS=	7zz:archivers/7-zip \
		cabextract:archivers/cabextract

.include <bsd.port.mk>
