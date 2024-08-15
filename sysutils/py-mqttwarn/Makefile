PORTNAME=	mqttwarn
DISTVERSION=	0.35.0
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Subscribe to MQTT topics and notify pluggable services
WWW=		https://github.com/jpmens/mqttwarn

LICENSE=	EPL

# based on setup.py : tests_require=extras['test'],
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}versioningit>=0:devel/py-versioningit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}attrs>=19.3.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docopt>=0.6.2:devel/py-docopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}funcy>0:devel/py-funcy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.18.2:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paho-mqtt>=1.4.0:net/py-paho-mqtt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.22.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.13.0:devel/py-six@${PY_FLAVOR}

USES=		python shebangfix

USE_PYTHON=	autoplist concurrent pep517
SHEBANG_REGEX=	'.*\.py$$'

NO_ARCH=	yes

# Most of what is in setup.py under extras is supported.
# The following were omitted because their dependencies are not found in the
# FreeBSD port tree: AMQP APPRISE ASTERISK FBCHAT IOHUB NMA NSCA OSXNOTIFY PASTEBINPUB PROWL PUSHBULLET
#                    SLACK TOOTPASTE XIVELY XMPP
OPTIONS_DEFINE=	APNS CELERY DNSUPDATE DOCS EXAMPLES GSS2 MYSQL POSTGRES REDISPUB \
		RRDTOOL SERIAL SSH TWILIO TWITTER WEBSOCKET

USERS=		mqttwarn
GROUPS=		mqttwarn

SUB_FILES=	mqttwarn pkg-message

APNS_DESC=	Apple Push Notifications
CELERY_DESC=	Asynchronous task queue/job queue
DNSUPDATE_DESC=	DNS updates
GSS2_DESC=	Google Docs Spreadsheet 2
MYSQL_DESC=	MySQL plugin
POSTGRES_DESC=	PostgreSQL Plugin
REDISPUB_DESC=	Publishes to a Redis channel
RRDTOOL_DESC=	Updates a round robin database created by rrdtool
SERIAL_DESC=	Serial port
SSH_DESC=	ssh plugin
TWILIO_DESC=	Use Twilio API to send messages
TWITTER_DESC=	Notifications to Twitter accounts
WEBSOCKET_DESC=	Websocket

APNS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}apns2>=2.0.1:devel/py-apns2@${PY_FLAVOR}
CELERY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}celery>0:devel/py-celery@${PY_FLAVOR}
DNSUPDATE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>=1.15.0:dns/py-dnspython@${PY_FLAVOR}
GSS2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gspread>=2.1.10:net/py-gspread@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}oauth2client>=4.1.2:security/py-oauth2client@${PY_FLAVOR}
MYSQL_USES=		mysql
POSTGRES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=2.7.4:databases/py-psycopg2@${PY_FLAVOR}
REDISPUB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=2.10.6:databases/py-redis@${PY_FLAVOR}
RRDTOOL_LIB_DEPENDS=	librrd.so:databases/rrdtool
RRDTOOL_RUN_DEPENDS=	rrdtool>0.1.12:databases/rrdtool
SERIAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyserial>3.40:comms/py-pyserial@${PY_FLAVOR}
SSH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>2.4.1:security/py-paramiko@${PY_FLAVOR}
TWILIO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twilio>6.11.0:devel/py-twilio@${PY_FLAVOR}
TWITTER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-twitter>=3.4.1:net/py-python-twitter@${PY_FLAVOR}
WEBSOCKET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}websocket-client>=0.47.0:www/py-websocket-client@${PY_FLAVOR}

post-patch:
	@${RM} ${WRKSRC}/tests/bad_funcs.py

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs -o addopts=

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/mqttwarn ${STAGEDIR}${PREFIX}/etc/rc.d
	@${ECHO_CMD} "etc/rc.d/mqttwarn" >> ${TMPPLIST}

	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/mqttwarn/examples/basic/mqttwarn.ini ${STAGEDIR}${ETCDIR}/mqttwarn.ini.sample
	@${ECHO_CMD} "@dir ${ETCDIR}" >> ${TMPPLIST}
	@${ECHO_CMD} "@sample(mqttwarn,mqttwarn,0640) ${ETCDIR}/mqttwarn.ini.sample" >> ${TMPPLIST}

	${MKDIR} ${STAGEDIR}/var/run/mqttwarn
	@${ECHO_CMD} "@dir /var/run/mqttwarn" >> ${TMPPLIST}

	${MKDIR} ${STAGEDIR}/var/log/mqttwarn
	@${ECHO_CMD} "@dir(mqttwarn,mqttwarn,) /var/log/mqttwarn" >> ${TMPPLIST}

.include <bsd.port.mk>
