# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	relatorio
PORTVERSION=	0.8.0
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Templating library able to output odt and pdf files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Genshi>=0.5:textproc/py-genshi@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.0:devel/py-lxml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}magic>=0:devel/py-magic@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycha>=0.4.0:graphics/py-pycha@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
