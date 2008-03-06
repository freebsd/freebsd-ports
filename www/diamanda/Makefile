# New ports collection makefile for:	www/diamanda
# Date created:				11 January 2008
# Whom:	      				Oleg Ukraincev <oleg@ht-systems.ru>
#
# $FreeBSD$
#

PORTNAME=	diamanda
PORTVERSION=	0.0.${SNAPSHOT:S/.//g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${SNAPSHOT}

MAINTAINER=	oleg@ht-systems.ru
COMMENT=	A set of useful Django applications

SNAPSHOT=	2007.04.26

WRKSRC=	${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
NO_BUILD=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
SUB_FILES=	pkg-message

RUN_DEPENDS+=\
${PYTHON_SITELIBDIR}/Django-0.96.1-py${PYTHON_DEFAULT_VERSION:S/python//}.egg-info:${PORTSDIR}/www/py-django
#'cause diamanda release currently doesn't work with django-devel branch
RUN_DEPENDS+=\
${PYTHON_SITELIBDIR}/stripogram/__init__.py:${PORTSDIR}/textproc/py-stripogram
RUN_DEPENDS+=\
${PYTHON_SITELIBDIR}/polib.py:${PORTSDIR}/devel/py-polib
RUN_DEPENDS+=\
${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/home/piotr/svn/diamanda|${PREFIX}/${WWWDIR}|g' ${WRKSRC}/settings.py ${WRKSRC}/urls.py

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
