# New ports collection makefile for:	py-django-photologue
# Date created:				12 January 2012
# Whom:					Kevin Golding <ports@caomhin.org>
#
# $FreeBSD$
#

PORTNAME=	django-photologue
PORTVERSION=	2.2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Reusable gallery application for Django

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django \
	${LOCALBASE}/bin/pildriver.py:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_ZIP=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

OPTIONS=	TAGGING "Enable tagging" On

.include <bsd.port.options.mk>

.if !defined(WITHOUT_TAGGING)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/tagging/models.py:${PORTSDIR}/www/py-django-tagging
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
