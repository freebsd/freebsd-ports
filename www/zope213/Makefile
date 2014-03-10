# $FreeBSD$

PORTNAME=	zope213
PORTVERSION=	2.13.22
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
DISTNAME=	Zope2-${PORTVERSION}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Object-based web application platform Version 2.13

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}AccessControl>=2.13.2:${PORTSDIR}/security/py-AccessControl \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:${PORTSDIR}/devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:${PORTSDIR}/devel/py-DateTime \
		${PYTHON_PKGNAMEPREFIX}DocumentTemplate>=0:${PORTSDIR}/devel/py-DocumentTemplate \
		${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:${PORTSDIR}/devel/py-ExtensionClass \
		${PYTHON_PKGNAMEPREFIX}Missing>=0:${PORTSDIR}/devel/py-Missing \
		${PYTHON_PKGNAMEPREFIX}MultiMapping>=0:${PORTSDIR}/devel/py-MultiMapping \
		${PYTHON_PKGNAMEPREFIX}Persistence>=0:${PORTSDIR}/devel/py-Persistence \
		${PYTHON_PKGNAMEPREFIX}Products.OFSP>=2.13.2:${PORTSDIR}/devel/py-Products.OFSP \
		${PYTHON_PKGNAMEPREFIX}Products.ZCatalog>=0:${PORTSDIR}/devel/py-Products.ZCatalog \
		${PYTHON_PKGNAMEPREFIX}Products.ZCTextIndex>=0:${PORTSDIR}/devel/py-Products.ZCTextIndex \
		${PYTHON_PKGNAMEPREFIX}Record>=0:${PORTSDIR}/devel/py-Record \
		${PYTHON_PKGNAMEPREFIX}RestrictedPython>=0:${PORTSDIR}/security/py-RestrictedPython \
		${PYTHON_PKGNAMEPREFIX}zconfig>=0:${PORTSDIR}/devel/py-zconfig \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:${PORTSDIR}/databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}ZopeUndo>=0:${PORTSDIR}/devel/py-ZopeUndo \
		${PYTHON_PKGNAMEPREFIX}docutils>=0:${PORTSDIR}/textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}initgroups>=0:${PORTSDIR}/devel/py-initgroups \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}tempstorage>=0:${PORTSDIR}/devel/py-tempstorage \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:${PORTSDIR}/devel/py-transaction \
		${PYTHON_PKGNAMEPREFIX}zdaemon>=0:${PORTSDIR}/sysutils/py-zdaemon \
		${PYTHON_PKGNAMEPREFIX}zExceptions>=0:${PORTSDIR}/devel/py-zExceptions \
		${PYTHON_PKGNAMEPREFIX}zLOG>=0:${PORTSDIR}/devel/py-zLOG \
		${PYTHON_PKGNAMEPREFIX}zope.browser>=0:${PORTSDIR}/devel/py-zope.browser \
		${PYTHON_PKGNAMEPREFIX}zope.browsermenu>=0:${PORTSDIR}/devel/py-zope.browsermenu \
		${PYTHON_PKGNAMEPREFIX}zope.browserpage>=0:${PORTSDIR}/devel/py-zope.browserpage \
		${PYTHON_PKGNAMEPREFIX}zope.browserresource>=0:${PORTSDIR}/devel/py-zope.browserresource \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:${PORTSDIR}/devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.container>=0:${PORTSDIR}/devel/py-zope.container \
		${PYTHON_PKGNAMEPREFIX}zope.contentprovider>=0:${PORTSDIR}/devel/py-zope.contentprovider \
		${PYTHON_PKGNAMEPREFIX}zope.contenttype>=0:${PORTSDIR}/devel/py-zope.contenttype \
		${PYTHON_PKGNAMEPREFIX}zope.deferredimport>=0:${PORTSDIR}/devel/py-zope.deferredimport \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:${PORTSDIR}/devel/py-zope.event \
		${PYTHON_PKGNAMEPREFIX}zope.exceptions>=0:${PORTSDIR}/devel/py-zope.exceptions \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:${PORTSDIR}/devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:${PORTSDIR}/textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>=0:${PORTSDIR}/devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:${PORTSDIR}/devel/py-zope.location \
		${PYTHON_PKGNAMEPREFIX}zope.pagetemplate>=0:${PORTSDIR}/devel/py-zope.pagetemplate \
		${PYTHON_PKGNAMEPREFIX}zope.processlifetime>=0:${PORTSDIR}/devel/py-zope.processlifetime \
		${PYTHON_PKGNAMEPREFIX}zope.proxy>=0:${PORTSDIR}/net/py-zope.proxy \
		${PYTHON_PKGNAMEPREFIX}zope.ptresource>=0:${PORTSDIR}/devel/py-zope.ptresource \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:${PORTSDIR}/devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:${PORTSDIR}/devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:${PORTSDIR}/security/py-zope.security \
		${PYTHON_PKGNAMEPREFIX}zope.sendmail>=0:${PORTSDIR}/mail/py-zope.sendmail \
		${PYTHON_PKGNAMEPREFIX}zope.sequencesort>=0:${PORTSDIR}/devel/py-zope.sequencesort \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:${PORTSDIR}/devel/py-zope.site \
		${PYTHON_PKGNAMEPREFIX}zope.size>=0:${PORTSDIR}/devel/py-zope.size \
		${PYTHON_PKGNAMEPREFIX}zope.structuredtext>=0:${PORTSDIR}/textproc/py-zope.structuredtext \
		${PYTHON_PKGNAMEPREFIX}zope.tal>=0:${PORTSDIR}/textproc/py-zope.tal \
		${PYTHON_PKGNAMEPREFIX}zope.tales>=3.5.0:${PORTSDIR}/devel/py-zope.tales \
		${PYTHON_PKGNAMEPREFIX}zope.testbrowser>=0:${PORTSDIR}/devel/py-zope.testbrowser \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=0:${PORTSDIR}/devel/py-zope.testing \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:${PORTSDIR}/devel/py-zope.traversing \
		${PYTHON_PKGNAMEPREFIX}zope.viewlet>=0:${PORTSDIR}/devel/py-zope.viewlet \
		${PYTHON_PKGNAMEPREFIX}Products.BTreeFolder2>=0:${PORTSDIR}/devel/py-Products.BTreeFolder2 \
		${PYTHON_PKGNAMEPREFIX}Products.ExternalMethod>=0:${PORTSDIR}/devel/py-Products.ExternalMethod \
		${PYTHON_PKGNAMEPREFIX}Products.MailHost>=0:${PORTSDIR}/mail/py-Products.MailHost \
		${PYTHON_PKGNAMEPREFIX}Products.MIMETools>=0:${PORTSDIR}/devel/py-Products.MIMETools \
		${PYTHON_PKGNAMEPREFIX}Products.PythonScripts>=0:${PORTSDIR}/devel/py-Products.PythonScripts \
		${PYTHON_PKGNAMEPREFIX}Products.StandardCacheManagers>=0:${PORTSDIR}/devel/py-Products.StandardCacheManagers \
		${PYTHON_PKGNAMEPREFIX}manuel>=0:${PORTSDIR}/devel/py-manuel

USES=		zip
USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	instance-message package-pkg-message pkg-message
SUB_LIST=	ZOPEINSTANCEBASE=${ZOPEINSTANCEBASE} \
		ZOPE_USER=${ZOPE_USER} \
		ZOPEINSTANCEDIR=${ZOPEINSTANCEDIR}

USE_RC_SUBR=		${PORTNAME}
ZOPE_USER?=		www
ZOPEINSTANCEBASE?=	${PREFIX}/www/Zope213
ZOPEINSTANCEDIR?=	${ZOPEINSTANCEBASE}/${ZOPEINSTANCENAME}

.if defined(BATCH)
ISBATCH=	--user admin:test123
.else
ISBATCH=	""
.endif

.if defined(INSTANCENAME)
ZOPEINSTANCENAME=	${INSTANCENAME}
.endif

instance:
	@${LOCALBASE}/bin/mkzopeinstance --dir ${ZOPEINSTANCEDIR} ${ISBATCH}
	@${CHOWN} ${ZOPE_USER}:${ZOPE_USER} ${ZOPEINSTANCEDIR}/var
	@${CHOWN} ${ZOPE_USER}:${ZOPE_USER} ${ZOPEINSTANCEDIR}/log
	@${SED} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/zope.conf_changes \
		| ${PATCH} --silent ${ZOPEINSTANCEDIR}/etc/zope.conf
	@${RM} ${ZOPEINSTANCEDIR}/etc/zope.conf.orig
	@${CAT} ${WRKDIR}/instance-message

post-install:
	@${CAT} ${WRKDIR}/pkg-message

pre-package:
	@${INSTALL_DATA} ${WRKDIR}/package-pkg-message ${PKGMESSAGE}

.include <bsd.port.mk>
