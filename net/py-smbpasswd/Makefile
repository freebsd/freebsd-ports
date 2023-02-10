PORTNAME=	smbpasswd
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	http://barryp.org/static/media/software/download/py-${PORTNAME}/${PORTVERSION}/ \
		PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SMB/CIFS password generation utility for Python
WWW=		https://barryp.org/software/py-smbpasswd

LICENSE=	GPLv2

# Python3 ready
USES=		python:3.6+ tar:tgz
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
