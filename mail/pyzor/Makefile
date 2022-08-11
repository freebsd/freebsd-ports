PORTNAME=	pyzor
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/SpamExperts/pyzor/commit/
PATCHFILES=	67b471dd168db9468548aef3ffadca9554164ac0.diff:-p1 \
		6332a429ed415187599ecce7d8a169ee19f0bbe5.diff:-p1

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Collaborative, networked system to detect and block spam

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdbm>=0:databases/py-gdbm@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
