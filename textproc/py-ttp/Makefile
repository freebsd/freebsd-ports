# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ttp
PORTVERSION=	0.5.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Template Text Parser

LICENSE=	MIT

USES=		dos2unix python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} > 3000
post-patch:
	@${RM} ${WRKSRC}/ttp/utils/load_python_exec_py2.py
.endif

.include <bsd.port.post.mk>
