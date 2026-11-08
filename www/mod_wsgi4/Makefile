PORTNAME=	mod_wsgi4
DISTVERSION=	4.9.4
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mod_wsgi-${DISTVERSION}

MAINTAINER=	adrian@freebsd.org
COMMENT=	Python WSGI 4.9.x adapter module for Apache
WWW=		https://www.modwsgi.org/

LICENSE=	APACHE20

USES=		apache autoreconf cpe python:2.7
USE_PYTHON=	flavors

.if !defined(WITH_CLUSTER_ALLOW_TECHNICAL_DEBTS)
IGNORE=		python 2.7 is EOL; set WITH_CLUSTER_ALLOW_TECHNICAL_DEBTS=yes in make.conf to build it
.endif

CPE_VENDOR=	modwsgi

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs="${APXS}" \
			--with-python="${PYTHON_CMD}"

CONFLICTS_INSTALL=	mod_wsgi

MOD_NAME=	mod_wsgi
AP_MOD_NAME=	mod_wsgi.so

SUB_FILES=	${APMOD_FILE}
APMOD_FILE=	270_${MOD_NAME}.conf.sample
PLIST_SUB+=	APMOD_FILE=${APMOD_FILE}
PLIST_SUB+=	APMODNAME_FILE=${AP_MOD_NAME}

pre-everything::
	@${ECHO_MSG} "======================= ATTENTION! ======================"
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to use daemon mode you will need to make sure"
	@${ECHO_MSG} "Apache and APR include thread support."
	@${ECHO_MSG}
	@${ECHO_MSG} "========================================================="

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${INSTALL_DATA} ${WRKDIR}/${APMOD_FILE} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${MOD_NAME}.so

.include <bsd.port.mk>
