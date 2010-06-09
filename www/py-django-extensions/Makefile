# New ports collection makefile for:	py-django-extensions
# Date created:				19 May 2010
# Whom:					Kevin Golding <ports@caomhin.org>
#
# $FreeBSD$
#

PORTNAME=	django-extensions
PORTVERSION=	0.5
CATEGORIES=	www python
MASTER_SITES=	http://www.caomhin.org/geek/ports/ \
		http://download.github.com/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django-extensions-django-extensions-0.5-0-gb4b8e5c

MAINTAINER=	ports@caomhin.org
COMMENT=	Global custom management extensions for the Django Framework

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django

WRKSRC=		${WRKDIR}/${DISTNAME:C/0\.5-0-g//g}
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS=	DOCS "Install HTML documentation (requires Sphinx)" Off

.include <bsd.port.options.mk>

.if defined(WITH_DOCS)
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sphinx>0:${PORTSDIR}/textproc/py-sphinx
PORTDOCS=	*
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

.include <bsd.port.mk>
