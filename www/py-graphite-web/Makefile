# Created by: Evan Sarmiento <esarmiento@wayfair.com>
# $FreeBSD$

PORTNAME=	graphite-web
PORTVERSION=	0.9.12
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://github.com/graphite-project/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Enterprise scalable realtime graphing platform

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=1.8.10:${PORTSDIR}/graphics/py-cairo \
		${PYTHON_PKGNAMEPREFIX}carbon>=${PORTVERSION}:${PORTSDIR}/databases/py-carbon \
		${PYTHON_PKGNAMEPREFIX}django>=1.4:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}django-tagging>=0.3.1:${PORTSDIR}/www/py-django-tagging \
		xorg-fonts-truetype>=0:${PORTSDIR}/x11-fonts/xorg-fonts-truetype

FETCH_ARGS=	-o ${DISTNAME}${EXTRACT_SUFX}
USE_PYTHON=	2
USE_PYTHON=	distutils
SUB_FILES=	pkg-message
SUB_LIST+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP} DATADIR=${DATADIR}

post-patch:
	@${RM} ${WRKSRC}/bin/build-index.sh.orig
	@${RM} ${WRKSRC}/bin/run-graphite-devel-server.py
	@${REINPLACE_CMD} -i '' -e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/bin/build-index.sh \
		${WRKSRC}/conf/graphite.wsgi.example \
		${WRKSRC}/setup.cfg \
		${WRKSRC}/setup.py \
		${WRKSRC}/webapp/graphite/local_settings.py.example

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/examples
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/examples)
	@${MKDIR} ${STAGEDIR}${DATADIR}/content
	@(cd ${WRKSRC}/webapp/content && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/content)
	@${MKDIR} ${STAGEDIR}/var/log/graphite/webapp
	@${MKDIR} ${STAGEDIR}/var/db/graphite
	@${CHOWN} ${WWWOWN} ${STAGEDIR}/var/log/graphite
	@${CHOWN} ${WWWOWN} ${STAGEDIR}/var/db/graphite
	@${CP} ${STAGEDIR}${PYTHON_SITELIBDIR}/graphite/local_settings.py.example ${STAGEDIR}${PREFIX}/etc/graphite/local_settings.py.example
	@${LN} -s ${PREFIX}/etc/graphite/local_settings.py ${STAGEDIR}${PYTHON_SITELIBDIR}/graphite/local_settings.py

.include <bsd.port.mk>
