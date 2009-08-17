# New ports collection makefile for:	www/diamanda
# Date created:				11 January 2008
# Whom:	      				Oleg Ukraincev <oleg@ht-systems.ru>
#
# $FreeBSD$
#

PORTNAME=	diamanda
PORTVERSION=	0.0.${SNAPSHOT:S/.//g}
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${SNAPSHOT}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of useful Django applications

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/__init__.py:${PORTSDIR}/www/py-django \
		${PYTHON_SITELIBDIR}/stripogram/__init__.py:${PORTSDIR}/textproc/py-stripogram \
		${PYTHON_SITELIBDIR}/polib.py:${PORTSDIR}/devel/py-polib \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging

SNAPSHOT=	2007.04.26

WRKSRC=	${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
NO_BUILD=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
SUB_FILES=	pkg-message

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
