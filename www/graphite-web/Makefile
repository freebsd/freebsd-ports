# New ports collection makefile for:	graphite-web
# Date created:		2011-07-22
# Whom:			Scott Sanders <ssanders@taximagic.com>
#
# $FreeBSD$
#

PORTNAME=	graphite-web
PORTVERSION=	0.9.10
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://launchpad.net/graphite/0.9/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ssanders@taximagic.com
COMMENT=	Graphite is a highly scalable real-time graphing system

# un-comment when the latest bsd.licenses.db.mk is used everywhere
# http://www.freebsd.org/cgi/query-pr.cgi?pr=163521
# LICENSE=	AL2

MAKE_JOBS_SAFE=	yes

USE_PYTHON=	2.4+
USE_PYDISTUTILS=yes
PYDISTUTILS_EGGINFODIR=	${WWWDIR}/webapp

FETCH_ARGS=	"-pRr"		# default '-AFpr' prevents 302 redirects by launchpad

RUN_DEPENDS+=	${PYTHON_LIBDIR}/site-packages/cairo/__init__.py:${PORTSDIR}/graphics/py-cairo \
		${PYTHON_LIBDIR}/site-packages/django/__init__.py:${PORTSDIR}/www/py-django \
		${PYTHON_LIBDIR}/site-packages/whisper.py:${PORTSDIR}/databases/py-whisper \
		${PYTHON_PKGNAMEPREFIX}django-tagging>=0:${PORTSDIR}/www/py-django-tagging \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:${PORTSDIR}/devel/py-pytz

OPTIONS=	APACHE "Use apache as webserver" on \
		CARBON "Build carbon backend " on \
		MODPYTHON3 "Enable mod_python3 support" off \
		MODWSGI3 "Enable mod_wsgi3 support" on \
		SQLITE3 "Enable sqlite3 support" on \
		MYSQL "Enable MySQL support" off

GRAPHITE_ROOT?=		${WWWDIR}

.include <bsd.port.options.mk>

.if !defined(WITHOUT_CARBON)
RUN_DEPENDS+=	${PYTHON_LIBDIR}/site-packages/carbon/__init__.py:${PORTSDIR}/databases/py-carbon
.endif

.if !defined(WITHOUT_APACHE)
USE_APACHE_RUN=	20+
.endif

.if !defined(WITHOUT_MODPYTHON3)
RUN_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_python.so:${PORTSDIR}/www/mod_python3
.endif

.if !defined(WITHOUT_MODWSGI3)
RUN_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_wsgi.so:${PORTSDIR}/www/mod_wsgi3
.endif

.if !defined(WITHOUT_MYSQL)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:${PORTSDIR}/databases/py-MySQLdb
.endif

.if !defined(WITHOUT_SQLITE3)
USE_SQLITE=	3
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3
.endif

.if !defined(WITHOUT_MODPYTHON3) && defined(WITHOUT_APACHE)
IGNORE=	mod_python3 needs Apache, please select Apache
.endif

.if !defined(WITHOUT_MODWSGI3) && defined(WITHOUT_APACHE)
IGNORE=	mod_wsgi3 needs Apache, please select Apache
.endif

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS+=	--install-data=${WWWDIR} \
				--install-lib=${WWWDIR} \
				--install-scripts=${WWWDIR}/graphite/bin

post-patch:
	@${REINPLACE_CMD} -e "s|%%WWWDIR%%|${WWWDIR}|g" ${WRKSRC}/setup.cfg \
		${WRKSRC}/bin/build-index.sh \
		${WRKSRC}/conf/graphite.wsgi.example
	@${REINPLACE_CMD} -e "s|%%GRAPHITE_ROOT%%|${GRAPHITE_ROOT}|g" ${WRKSRC}/examples/example-graphite-vhost.conf
	@${RM} -f ${WRKSRC}/bin/build-index.sh.* ${WRKSRC}/examples/*.bak ${WRKSRC}/examples/*.orig

do-install:
	(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py install)
	# XXX this might be too permissive, will see what priv is acctually needed
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${GRAPHITE_ROOT}/storage

.include <bsd.port.post.mk>
