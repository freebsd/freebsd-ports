# $FreeBSD$

PORTNAME=	alot
DISTVERSION=	0.7
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mail@dbalan.in
COMMENT=	Terminal MUA using Notmuch mail

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}notmuch>=0.13:mail/py-notmuch@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gpgme>0:security/py-gpgme@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>4.7.0:devel/py-configobj@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-magic>0:devel/py-python-magic@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>10.2.0:devel/py-twisted@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwidtrees>1.0:devel/py-urwidtrees@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service_identity>=0:security/py-service_identity@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
