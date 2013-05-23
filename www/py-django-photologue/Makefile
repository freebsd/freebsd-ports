# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	django-photologue
PORTVERSION=	2.6.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Reusable gallery application for Django

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django \
	${LOCALBASE}/bin/pildriver.py:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
USE_ZIP=	yes

OPTIONSFILE= ${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=		TAGGING
OPTIONS_DEFAULT=	TAGGING

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTAGGING}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/tagging/models.py:${PORTSDIR}/www/py-django-tagging
.endif

.include <bsd.port.mk>
