# New ports collection makefile for:	turbogears
# Date created:		2006-01-08
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	TurboGears
PORTVERSION=	0.8.9
CATEGORIES=	www python
MASTER_SITES=	http://www.turbogears.org/download/eggs/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	nivit@email.it
COMMENT=	Python-Based Framework for Rapid Web Development

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools \
		kid:${PORTSDIR}/devel/py-kid \
		sqlobject-admin:${PORTSDIR}/databases/py-sqlobject \
		${PYTHON_SITELIBDIR}/cherrypy/__init__.py:${PORTSDIR}/www/py-cherrypy \
		${PYTHON_SITELIBDIR}/cElementTree.so:${PORTSDIR}/devel/py-celementtree \
		${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree \
		${PYTHON_SITELIBDIR}/formencode/__init__.py:${PORTSDIR}/www/py-formencode \
		${PYTHON_SITELIBDIR}/json.py:${PORTSDIR}/devel/py-json-py \
		${PYTHON_SITELIBDIR}/TestGears-0.2-py2.4.egg:${PORTSDIR}/devel/py-testgears

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

OPTIONS=	CHEETAH	"Install py-cheetah add-on" off
# bypass infrastructure bug (taken from www/py-django)
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

PLIST_SUB=	PORTVERSION=${PORTVERSION} EGGEXT=py2.4.egg
SUB_FILES=	pkg-deinstall
SUB_LIST=	EGGS=${EGGS} PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

EGGS=		${PORTNAME}-${PORTVERSION}-py2.4.egg
EASY_INSTALL=	easy_install

do-install:
	for FILE in ${DISTFILES}; do \
	    ${EASY_INSTALL} --no-deps --script-dir=${PREFIX}/bin ${DISTDIR}/$${FILE}; \
	done;

post-install:
	${RM} ${PYTHON_SITELIBDIR}/${PORTNAME}-${PORTVERSION}-py2.4.egg/EGG-INFO/requires.txt

.include <bsd.port.pre.mk>

.if defined(WITH_CHEETAH)
RUN_DEPENDS+=	cheetah:${PORTSDIR}/devel/py-cheetah
.endif

.include <bsd.port.post.mk>
