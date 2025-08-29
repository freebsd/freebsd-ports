PORTNAME=	healthchecks
DISTVERSIONPREFIX=	v
DISTVERSION=	3.11
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Open-source cron job and background task monitoring service
WWW=		https://github.com/healthchecks/${PORTNAME}

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${ALL_DEPENDS}
RUN_DEPENDS=	${ALL_DEPENDS}

USES=		python shebangfix
USE_GITHUB=	yes

SHEBANG_FILES=	${WRKSRC}/manage.py

NO_ARCH=	yes
SUB_FILES=	hcks pkg-message uwsgi.ini
SUB_LIST=	HOMEDIR=${HEALTHCHECKS_HOMEDIR}

USERS=		${HEALTHCHECKS_USER}
GROUPS=		${HEALTHCHECKS_GROUP}

PLIST_SUB=	GROUP=${GROUPS:[1]} \
		HOMEDIR=${HEALTHCHECKS_HOMEDIR} \
		USER=${USERS:[1]}
PORTDOCS=	README.md

OPTIONS_DEFINE=		APPRISE DOCS MINIO
OPTIONS_DEFAULT=	APPRISE MINIO

APPRISE_DESC=	Enable support for Apprise integration
MINIO_DESC=	Enable support for external object storage

APPRISE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apprise>=0:net-im/py-apprise@${PY_FLAVOR}
MINIO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}minio>=0:devel/py-minio@${PY_FLAVOR}

HEALTHCHECKS_USER=	${PORTNAME}
HEALTHCHECKS_GROUP=	${HEALTHCHECKS_USER}

HEALTHCHECKS_HOMEDIR=	/var/db/${PORTNAME}

ALL_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiosmtpd>=0:mail/py-aiosmtpd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cronsim>=0:devel/py-cronsim@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django52>=0:www/py-django52@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django_compressor>=0:www/py-django_compressor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-django-stubs-ext>0:www/py-dj52-django-stubs-ext@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fido2>0:security/py-fido2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oncalendar>=0:devel/py-oncalendar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg>=0:databases/py-psycopg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycurl>=0:ftp/py-pycurl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyotp>=0:security/py-pyotp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}segno>=0:textproc/py-segno@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}statsd>=0:devel/py-statsd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}whitenoise>=0:www/py-whitenoise@${PY_FLAVOR}

do-build:
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${WRKSRC}/hc
	@${SETENV} \
		${PYTHON_CMD} ${WRKSRC}/manage.py compress --force
	@${SETENV} \
		${PYTHON_CMD} ${WRKSRC}/manage.py collectstatic --no-input

do-install:
	@${MKDIR} ${STAGEDIR}${HEALTHCHECKS_HOMEDIR}
	@cd ${WRKSRC} && \
	    ${COPYTREE_SHARE} ./hc ${STAGEDIR}${HEALTHCHECKS_HOMEDIR}
	@cd ${WRKSRC} && \
	    ${COPYTREE_SHARE} ./static ${STAGEDIR}${HEALTHCHECKS_HOMEDIR}
	@cd ${WRKSRC} && \
	    ${COPYTREE_SHARE} ./static-collected ${STAGEDIR}${HEALTHCHECKS_HOMEDIR}
	@cd ${WRKSRC} && \
	    ${COPYTREE_SHARE} ./templates ${STAGEDIR}${HEALTHCHECKS_HOMEDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/manage.py ${STAGEDIR}${HEALTHCHECKS_HOMEDIR}
	${INSTALL_DATA} ${WRKSRC}/search.db ${STAGEDIR}${HEALTHCHECKS_HOMEDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${STAGEDIR}${HEALTHCHECKS_HOMEDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/uwsgi.ini ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/hcks ${STAGEDIR}${LOCALBASE}/bin/hcks

post-install:
.for dir in run log
	@${MKDIR} ${STAGEDIR}/var/${dir}/${PORTNAME}
.endfor
	@${MKDIR} ${STAGEDIR}${HEALTHCHECKS_HOMEDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
