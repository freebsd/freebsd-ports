PORTNAME=	smbpasswd
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SMB/CIFS password generation utility for Python
WWW=		https://barryp.org/software/py-smbpasswd

LICENSE=	GPLv2

# Python3 ready
USES=		python tar:tgz
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.post.mk>
