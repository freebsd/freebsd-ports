# Created by: Evan Sarmiento <esarmiento@wayfair.com>
# $FreeBSD$

PORTNAME=	graphite-web
PORTVERSION=	0.9.12
CATEGORIES=	www python
MASTER_SITES=	https://github.com/graphite-project/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bsdports@wayfair.com
COMMENT=	Enterprise scalable realtime graphing platform

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=1.8.10:${PORTSDIR}/graphics/py-cairo \
		${PYTHON_PKGNAMEPREFIX}carbon>=${PORTVERSION}:${PORTSDIR}/databases/py-carbon \
		${PYTHON_PKGNAMEPREFIX}django>=1.4:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}django-tagging>=0.3.1:${PORTSDIR}/www/py-django-tagging

FETCH_ARGS=	-o ${DISTNAME}${EXTRACT_SUFX}
USE_PYTHON=	2
USE_PYDISTUTILS=yes

NO_STAGE=	yes
post-patch:
	@${MKDIR} ${WRKSRC}/graphite/webapp/
	@${CP} -LR ${WRKSRC}/webapp/content ${WRKSRC}/graphite/webapp
	@${RM} ${WRKSRC}/bin/build-index.sh.orig

post-install:
	@${ECHO} ${PYTHON_SITELIBDIR}
	${CHOWN} ${WWWOWN} ${PREFIX}/graphite/storage
	${CHOWN} ${WWWOWN} ${PREFIX}/graphite/storage/log/webapp
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
