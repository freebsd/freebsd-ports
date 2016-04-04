# $FreeBSD$

PORTNAME=	s3transfer
PORTVERSION=	0.0.1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bradleythughes@fastmail.fm
COMMENT=	Amazon S3 Transfer Manager for Python

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}botocore>=1.3.0:devel/py-botocore

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}futures>=2.2.0:devel/py-futures
.endif

.include <bsd.port.post.mk>
