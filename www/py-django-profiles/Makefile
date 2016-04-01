# Created by: Josh Paetzel <jpaetzel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	django-profiles
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://bitbucket.org/ubernostrum/django-profiles/get/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	User-profile application for Django

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:www/py-django18

WRKSRC=	${WRKDIR}/${PORTNAME}
USES=		python
USE_PYTHON=	distutils
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
