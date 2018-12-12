# $FreeBSD$

PORTNAME=	calendarserver
PORTVERSION=	9.1
PORTREVISION=	1
DISTVERSIONPREFIX=	CalendarServer-
CATEGORIES=	    www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	axel.rau@chaos1.de
COMMENT=	Calendar and Contacts Server from Apple (RFC 4791, RFC 6352)

LICENSE=	APACHE20

RUN_DEPENDS=	memcached:databases/memcached \
		${PYTHON_PKGNAMEPREFIX}calendar>=2.1:devel/py-calendar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyGreSQL>=5.0:databases/py-PyGreSQL@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.6.1:security/py-pycrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.5.3:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kerberos>=1.2.5:security/py-kerberos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=16.0.0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pg8000>=1.10.6:databases/py-pg8000@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=4.3.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2016.7:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service_identity>=16.0.0:security/py-service_identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=1.1.10:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twext>=0.20170227:devel/py-twext@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=16.6.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xattr>=0.7.8:devel/py-xattr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=4.1.3:devel/py-zope.interface@${PY_FLAVOR}

PORTDOCS=	*
PORTEXAMPLES=	*
OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		pgsql:9.1+ python:2.7
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes
GH_ACCOUNT=	apple
GH_PROJECT=	ccs-calendarserver

NO_ARCH=yes

SUB_FILES=	pkg-message
SUB_LIST+=	USER=${USERS}

USE_RC_SUBR=	caldavd
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

ETCDIR=		${PREFIX}/etc/caldavd
SHAREDIR=	${PREFIX}/share/caldavd
DBDIR=		/var/db/caldavd
LOGDIR=		/var/log/caldavd
RUNDIR=		/var/run/caldavd
PLIST_SUB=	USER=${USERS} GROUP=${GROUPS} \
		ETCDIR=${ETCDIR} \
		DBDIR=${DBDIR} \
		LOGDIR=${LOGDIR} \
		RUNDIR=${RUNDIR}

CALDAVD_USER=	caldavd
USERS=			${CALDAVD_USER}
GROUPS=			${CALDAVD_USER}

post-patch:
	@${REINPLACE_CMD} -e 's|"{}a1+unknown".format(base_version)|"${PORTVERSION}"|' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|"/etc/caldavd/caldavd.plist"|"${ETCDIR}/caldavd.plist"|g' ${WRKSRC}/twistedcaldav/stdconfig.py
	@${REINPLACE_CMD} -e 's|/etc/caldavd|${ETCDIR}|g' ${WRKSRC}/conf/caldavd.plist
	@${REINPLACE_CMD} -e 's|daemon|caldavd|g' ${WRKSRC}/conf/caldavd.plist
	@${REINPLACE_CMD} -e 's|/var/run|/var/run/caldavd|g' ${WRKSRC}/conf/caldavd.plist

post-install:
	${MKDIR} ${STAGEDIR}${DBDIR}/Data/Documents
	${MKDIR} ${STAGEDIR}${DBDIR}/Documents
	${MKDIR} ${STAGEDIR}${ETCDIR}/auth
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/conf && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	(cd ${STAGEDIR}${DOCSDIR} && ${RM} *.8)
	##(cd ${WRKSRC}/doc && \
	##	for i in `ls |${GREP} -v '.8'`; do \
	##	${MKDIR} ${STAGEDIR}${DOCSDIR}/$${i} && \
	##	${INSTALL_MAN} ${WRKSRC}/doc/$${i}/* \
	##	${STAGEDIR}${DOCSDIR}/$${i}; \
	##	done)
	${CP} -p ${WRKSRC}/txdav/common/datastore/sql_schema/current.sql \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/*.8 ${STAGEDIR}${PREFIX}/man/man8
	${MKDIR} ${STAGEDIR}${LOGDIR}
	${MKDIR} ${STAGEDIR}${RUNDIR}

.include <bsd.port.mk>
