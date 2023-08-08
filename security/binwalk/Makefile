PORTNAME=	binwalk
PORTVERSION=	2.3.3
DISTVERSIONPREFIX=	v
CATEGORIES=	security python

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Search binary images for embedded files and executable code
WWW=		http://www.binwalk.org

LICENSE=	MIT

RUN_DEPENDS=	7zz:archivers/7-zip \
		cabextract:archivers/cabextract

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	ReFirmLabs
USE_PYTHON=	autoplist distutils optsuffix concurrent

.include <bsd.port.mk>
