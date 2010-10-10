# New ports collection makefile for:	py-django-registration
# Date created:				22 November 2009
# Whom:					Kevin Golding <ports@caomhin.org>
#
# $FreeBSD$
#

PORTNAME=	django-registration
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://bitbucket.org/ubernostrum/django-registration/get/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@caomhin.org
COMMENT=	A user-registration application for Django

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django

WRKSRC=	${WRKDIR}/${PORTNAME}
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_GETTEXT=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
