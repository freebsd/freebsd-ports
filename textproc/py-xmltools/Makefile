# ex:ts=8
# Ports collection Makefile for:	xmltools
# Date created:			Jan 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmltools
PORTVERSION=	1.3.5
CATEGORIES=	textproc python
MASTER_SITES=	ftp://ftp.logilab.org/pub/xmltools/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_VERSION} == "python1.5" || ${PYTHON_VERSION} == "python1.6"
XMLDIR=		xml
.else
XMLDIR=		_xmlplus
.endif

RUN_DEPENDS=	${PYXML} \
		${PYTHON_SITELIBDIR}/GDK.py:${PORTSDIR}/x11-toolkits/py-gtk \
		${PYTHON_SITELIBDIR}/${XMLDIR}/xpath/__init__.py:${PORTSDIR}/textproc/py-4suite

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

.include <bsd.port.post.mk>
