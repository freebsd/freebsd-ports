# New ports collection makefile for:	py-satchmo
# Date created:				12 December 2009
# Whom:					Kevin Golding <ports@caomhin.org>
#
# $FreeBSD$
#

PORTNAME=	satchmo
PORTVERSION=	0.9.0
CATEGORIES=	www python
MASTER_SITES=	http://bitbucket.org/chris1610/satchmo/get/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	v${PORTVERSION:C/([[:digit:]]\.[[:digit:]])\.[[:digit:]]/\1/g}

MAINTAINER=	ports@caomhin.org
COMMENT=	Shopping cart application for Django.

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django \
		${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab\
		${PYTHON_SITELIBDIR}/trml2pdf/__init__.py:${PORTSDIR}/print/py-trml2pdf \
		${PYTHON_SITELIBDIR}/registration/__init__.py:${PORTSDIR}/www/py-django-registration \
		${PYTHON_SITELIBDIR}/yaml/__init__.py:${PORTSDIR}/devel/py-yaml \
		${LOCALBASE}/bin/pildriver.py:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/sorl/thumbnail/__init__.py:${PORTSDIR}/graphics/py-sorl-thumbnail

WRKSRC=	${WRKDIR}/${PORTNAME}
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_EGG=	Satchmo-${PORTVERSION:C/([[:digit:]]\.[[:digit:]])\./\1_/g}-${PYTHON_VERSION:S/thon//}.egg
PYEASYINSTALL_UNINSTALLARGS=	-q -m -S ${PYTHON_SITELIBDIR} \
 ${PYDISTUTILS_PKGNAME}==${PYDISTUTILS_PKGVERSION:C/([[:digit:]]\.[[:digit:]])\./\1_/g}

.include <bsd.port.pre.mk>

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}django-threaded-multihost>=0:${PORTSDIR}/www/py-django-threaded-multihost \
	${PYTHON_PKGNAMEPREFIX}django-app-plugins>=0:${PORTSDIR}/www/py-django-app-plugins \
	${PYTHON_PKGNAMEPREFIX}django-signals-ahoy>=0:${PORTSDIR}/www/py-django-signals-ahoy

.if ${PYTHON_REL} < 250
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree
.endif

.if defined(WITH_DOCS)
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sphinx>0:${PORTSDIR}/textproc/py-sphinx
BUILD_DEPENDS+=	rst2xml>0:${PORTSDIR}/textproc/py-docutils
.endif

post-build:
.if defined(WITH_DOCS)
	cd ${WRKSRC}/docs && ${MAKE} html
.endif

post-install:
.if defined(WITH_DOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/_build/html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
