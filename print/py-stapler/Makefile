# Created by: Ben Woods <woodsb02@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stapler
PORTVERSION=	0.3.3
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
#DISTNAME=	PyPDF2-${PORTVERSION}

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Manipulate PDF documents from the command line

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}more-itertools>=2.2:devel/py-more-itertools@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdf2>=1.24:print/py-pdf2@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
