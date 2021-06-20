# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	mog
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Different take on the UNIX tool cat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mdv>0:devel/py-mdv@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:3.6+
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils concurrent optsuffix
NO_ARCH=	yes

GH_ACCOUNT=	witchard

.include <bsd.port.mk>
