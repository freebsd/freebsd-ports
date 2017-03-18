# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mog
PORTVERSION=	0.6.0
CATEGORIES=	sysutils

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Different take on the UNIX tool cat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments \
		mdv:devel/py-mdv
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

GH_ACCOUNT=	witchard

.include <bsd.port.mk>
