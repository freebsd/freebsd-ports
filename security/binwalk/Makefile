# $FreeBSD$

PORTNAME=	binwalk
PORTVERSION=	2.0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	security python

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Search binary images for embedded files and executable code

LICENSE=	MIT

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	devttys0
GH_TAGNAME=	38218b
USE_PYTHON=	autoplist distutils

RUN_DEPENDS=	7z:${PORTSDIR}/archivers/p7zip \
		cabextract:${PORTSDIR}/archivers/cabextract

.include <bsd.port.mk>
