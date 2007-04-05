# ex:ts=8
# Ports collection makefile for:	py-rdflib
# Date created:			Aug 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rdflib
PORTVERSION=	2.4.0
CATEGORIES=	textproc python
MASTER_SITES=	http://rdflib.net/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	A Python library for RDF manipulation

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PYRDFLIB_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}-${OSINFOS}.egg
OSINFOS=	${OPSYS:L}-${OSRELEASE}-${ARCH}

PLIST_SUB+=	PYRDFLIB_EGG=${PYRDFLIB_EGG}

pre-build:
	@cd ${WRKSRC} && ${PYTHON_CMD} setup.py setopt -c build -o build-platlib -s lib.${OSINFOS}
	@cd ${WRKSRC} && ${PYTHON_CMD} setup.py setopt -c build -o build-temp -s temp.${OSINFOS}-${PYTHON_VER}
	@cd ${WRKSRC} && ${PYTHON_CMD} setup.py setopt -c bdist_egg -o plat-name -s ${OSINFOS}
	@cd ${WRKSRC} && ${PYTHON_CMD} setup.py setopt -c bdist -o plat-name -s ${OSINFOS}

.include <bsd.port.pre.mk>

OSRELEASE!=	uname -r

.include <bsd.port.post.mk>
