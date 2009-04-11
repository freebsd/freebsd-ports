# ex:ts=8
# Ports collection makefile for:	py-rdflib
# Date created:			Aug 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rdflib
PORTVERSION=	2.4.1
CATEGORIES=	textproc python
MASTER_SITES=	http://rdflib.net/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	A Python library for RDF manipulation

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

FETCH_ARGS=	-prR

pre-build:
	@cd ${WRKSRC} && ${PYTHON_CMD} setup.py setopt -c build -o build-platlib -s lib.${PYEASYINSTALL_OSARCH:S/^-//}
	@cd ${WRKSRC} && ${PYTHON_CMD} setup.py setopt -c build -o build-temp -s temp.${PYEASYINSTALL_OSARCH:S/^-//}-${PYTHON_VER}
	@cd ${WRKSRC} && ${PYTHON_CMD} setup.py setopt -c bdist_egg -o plat-name -s ${PYEASYINSTALL_OSARCH:S/^-//}
	@cd ${WRKSRC} && ${PYTHON_CMD} setup.py setopt -c bdist -o plat-name -s ${PYEASYINSTALL_OSARCH:S/^-//}

.include <bsd.port.mk>
