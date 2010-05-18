# New ports collection makefile for:	trac-spam-filter
# Date created:	23 September 2007
# Whom:					sutra
#
# $FreeBSD$
#

PORTNAME=	TracSpamFilter
PORTVERSION=	0.2.1
PORTREVISION=	4
CATEGORIES=	www devel python
MASTER_SITES=	http://zhoushuqun.com/files/ \
		http://freebsd.unixfreunde.de/sources/
PKGNAMEPREFIX=	trac-

MAINTAINER=	zhoushuqun@gmail.com
COMMENT=	Allow different ways to reject contributions that contain spam

RUN_DEPENDS=	tracd:${PORTSDIR}/www/trac
BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}dev

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_NOEGGINFO=	yes
PLIST_SUB+=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION} PYTHONVERSION=${_PYTHON_VERSION}

do-build:
	cd ${WRKSRC}; \
	${PYTHON_CMD} setup.py bdist_egg

do-install:
.for i in *
	${INSTALL_DATA} ${WRKSRC}/dist/${i} ${PYTHON_SITELIBDIR}/
.endfor

.include <bsd.port.mk>
