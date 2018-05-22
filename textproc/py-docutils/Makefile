# Created by: ijliao
# $FreeBSD$

PORTNAME=	docutils
PORTVERSION=	0.14
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python Documentation Utilities

LICENSE=	BSD2CLAUSE GPLv3+ PD PSFL
LICENSE_COMB=	multi

PORTSCOUT=	limit:^[0-9\.]*$$

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist concurrent distutils

OPTIONS_DEFINE=	PYGMENTS

PYGMENTS_DESC=		Syntax highlighting
PYGMENTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=1.6:textproc/py-pygments@${PY_FLAVOR}

.include <bsd.port.pre.mk>

do-test:
.if ${PYTHON_VER} < 3
	@cd ${WRKSRC}/test && ${PYTHON_CMD} alltests.py
.else
	@cd ${WRKSRC}/test3 && ${PYTHON_CMD} alltests.py
.endif

.include <bsd.port.post.mk>
