# $FreeBSD$

PORTNAME=	moviepy
PORTVERSION=	0.2.3.2
PORTREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Video editing with Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE.txt

RUN_DEPENDS=	convert:graphics/ImageMagick \
		${PYTHON_PKGNAMEPREFIX}decorator>=4.0.11:devel/py-decorator@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imageio>=2.1.2:graphics/py-imageio@${FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.11.2:misc/py-tqdm@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
