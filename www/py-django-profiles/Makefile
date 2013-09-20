# Created by: Josh Paetzel <jpaetzel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	django-profiles
PORTVERSION=	0.2
CATEGORIES=	www python
MASTER_SITES=	http://bitbucket.org/ubernostrum/django-profiles/get/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	A user-profile application for Django

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django

WRKSRC=	${WRKDIR}/${PORTNAME}
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
