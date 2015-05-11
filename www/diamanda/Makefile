# Created by: Oleg Ukraincev <oleg@ht-systems.ru>
# $FreeBSD$

PORTNAME=	diamanda
PORTVERSION=	0.0.${SNAPSHOT:S/.//g}
PORTREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${SNAPSHOT}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of useful Django applications

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/__init__.py:${PORTSDIR}/www/py-django \
		${PYTHON_SITELIBDIR}/stripogram/__init__.py:${PORTSDIR}/textproc/py-stripogram \
		${PYTHON_SITELIBDIR}/polib.py:${PORTSDIR}/devel/py-polib \
		${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow

SNAPSHOT=	2007.04.26

WRKSRC=	${WRKDIR}/${PORTNAME}

BROKEN=		Does not work with current django
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-05-26
NO_BUILD=	yes
USES=		gettext python tar:bzip2
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/home/piotr/svn/diamanda|${PREFIX}/${WWWDIR}|g' ${WRKSRC}/settings.py ${WRKSRC}/urls.py

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}

.include <bsd.port.post.mk>
