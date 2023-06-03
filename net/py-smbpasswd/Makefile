PORTNAME=	smbpasswd
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SMB/CIFS password generation utility for Python
WWW=		https://barryp.org/software/py-smbpasswd

LICENSE=	GPLv2

# Python3 ready
USES=		python:3.6+ tar:tgz
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
