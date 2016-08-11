# $FreeBSD$

PORTNAME=	calendarserver
PORTVERSION=	8.0
CATEGORIES=	www python
MASTER_SITES=	http://www.lechner-rau.de/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	CalendarServer-${PORTVERSION}

MAINTAINER=	axel.rau@chaos1.de
COMMENT=	Calendar and Contacts Server from Apple (RFC 4791, RFC 6352)

LICENSE=	APACHE20

FETCH_DEPENDS=	svn:devel/subversion
BUILD_DEPENDS=	${FETCH_DEPENDS}
RUN_DEPENDS=	memcached:databases/memcached \
		${PYTHON_PKGNAMEPREFIX}calendar>=0.15423:devel/py-calendar \
		${PYTHON_PKGNAMEPREFIX}PyGreSQL>=4.1:databases/py-PyGreSQL \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.6.1:security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.4.2:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}openssl>=0.14:security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}pg8000>=1.10.2:databases/py-pg8000 \
		${PYTHON_PKGNAMEPREFIX}psutil>=3.4.2:sysutils/py-psutil \
		${PYTHON_PKGNAMEPREFIX}pytz>=2016.1:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}service_identity>=14.0.0:security/py-service_identity \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=1.1.9:devel/py-setproctitle \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7:databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.1:databases/py-sqlparse \
		${PYTHON_PKGNAMEPREFIX}twext>=0.15423:devel/py-twext \
		${PYTHON_PKGNAMEPREFIX}twisted>=15.4.0:devel/py-twisted \
		${PYTHON_PKGNAMEPREFIX}xattr>=0.7.5:devel/py-xattr \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=4.1.3:devel/py-zope.interface

USES=	pgsql:9.1+ python:2.7
USE_PYTHON=	autoplist distutils

SUB_FILES=	pkg-message
SUB_LIST+=	USER=${USERS}

USE_RC_SUBR=	caldavd
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

SVN_REPOSITORY_URL=	http://svn.calendarserver.org/repository/calendarserver
SVN_TAG1=	CalendarServer/tags/release/${DISTNAME}
SVN_CMD1=	svn export

LOGDIR=		/var/log/caldavd
SHAREDIR=	${PREFIX}/share/caldavd

ETCDIR=		${PREFIX}/etc/caldavd

CALDAVD_USER=	caldavd
USERS=		${CALDAVD_USER}
GROUPS=		${CALDAVD_USER}

maint-gen-distfile:
	@if [ ! -f "${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}" ] ; then \
		${MKDIR} ${WRKDIR} ; cd ${WRKDIR} ; ${RM} -Rf ${WRKDIR}/${DISTNAME} ; \
		${ECHO_MSG} "=> Checking out CalendarServer from svn.calendarserver.org/..."; \
		${SVN_CMD1} ${SVN_REPOSITORY_URL}/${SVN_TAG1} > /dev/null ; \
		${ECHO_MSG} "=> Creating tar archive ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}"; \
		cd ${WRKDIR} ; tar -czf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${DISTNAME} ; \
		${RM} -Rf ${WRKDIR}/${DISTNAME} ; \
	else \
		${ECHO_MSG} "===>	${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} found." ; \
	fi

post-patch:
	@${REINPLACE_CMD} -e 's|"{}.a1+unknown".format(base_version)|"8.0"|' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|"/etc/caldavd/caldavd.plist"|"${ETCDIR}/caldavd.plist"|g' ${WRKSRC}/twistedcaldav/stdconfig.py

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}/auth
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/conf && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	(cd ${WRKSRC}/doc && \
		for i in `ls |${GREP} -v '.8'`; do \
		${MKDIR} ${STAGEDIR}${DOCSDIR}/$${i} && \
		${INSTALL_MAN} ${WRKSRC}/doc/$${i}/* \
		${STAGEDIR}${DOCSDIR}/$${i}; \
		done)
	${CP} -p ${WRKSRC}/txdav/common/datastore/sql_schema/current.sql \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/*.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
