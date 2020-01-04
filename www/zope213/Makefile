# $FreeBSD$

PORTNAME=	zope213
PORTVERSION=	2.13.24
PORTREVISION=	1
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
DISTNAME=	Zope2-${PORTVERSION}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Object-based web application platform Version 2.13

DEPRECATED=	Outdated, uses EOLed python27
EXPIRATION_DATE=	2020-02-05

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}AccessControl>=2.13.2:security/py-AccessControl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:devel/py-DateTime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}DocumentTemplate>=0:devel/py-DocumentTemplate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:devel/py-ExtensionClass@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Missing>=0:devel/py-Missing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}MultiMapping>=0:devel/py-MultiMapping@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Persistence>=0:devel/py-Persistence@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.OFSP>=2.13.2:devel/py-Products.OFSP@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.ZCatalog>=0:devel/py-Products.ZCatalog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.ZCTextIndex>=0:devel/py-Products.ZCTextIndex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Record>=0:devel/py-Record@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}RestrictedPython>=0:security/py-RestrictedPython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zconfig>=0:devel/py-zconfig@${PY_FLAVOR} \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ZopeUndo>=0:devel/py-ZopeUndo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}initgroups>=0:devel/py-initgroups@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tempstorage>=0:devel/py-tempstorage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:devel/py-transaction@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zdaemon>=0:sysutils/py-zdaemon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zExceptions>=0:devel/py-zExceptions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zLOG>=0:devel/py-zLOG@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browser>=0:devel/py-zope.browser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browsermenu>=0:devel/py-zope.browsermenu@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browserpage>=0:devel/py-zope.browserpage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browserresource>=0:devel/py-zope.browserresource@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:devel/py-zope.configuration@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.container>=0:devel/py-zope.container@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.contentprovider>=0:devel/py-zope.contentprovider@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.contenttype>=0:devel/py-zope.contenttype@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.deferredimport>=0:devel/py-zope.deferredimport@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:devel/py-zope.event@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.exceptions>=0:devel/py-zope.exceptions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>=0:devel/py-zope.lifecycleevent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:devel/py-zope.location@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.pagetemplate>=0:devel/py-zope.pagetemplate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.processlifetime>=0:devel/py-zope.processlifetime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.proxy>=0:net/py-zope.proxy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.ptresource>=0:devel/py-zope.ptresource@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:security/py-zope.security@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.sendmail>=0:mail/py-zope.sendmail@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.sequencesort>=0:devel/py-zope.sequencesort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:devel/py-zope.site@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.size>=0:devel/py-zope.size@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.structuredtext>=0:textproc/py-zope.structuredtext@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.tal>=0:textproc/py-zope.tal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.tales>=3.5.0:devel/py-zope.tales@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.testbrowser>=0:devel/py-zope.testbrowser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=0:devel/py-zope.testing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:devel/py-zope.traversing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.viewlet>=0:devel/py-zope.viewlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.BTreeFolder2>=0:devel/py-Products.BTreeFolder2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.ExternalMethod>=0:devel/py-Products.ExternalMethod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.MailHost>=0:mail/py-Products.MailHost@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.MIMETools>=0:devel/py-Products.MIMETools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.PythonScripts>=0:devel/py-Products.PythonScripts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.StandardCacheManagers>=0:devel/py-Products.StandardCacheManagers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}manuel>=0:devel/py-manuel@${PY_FLAVOR}

USES=		python:-2.7
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

SUB_FILES=	pkg-message
SUB_LIST=	ZOPE_USER=${ZOPE_USER} \
		ZOPEINSTANCEDIR=${ZOPEINSTANCEDIR}

USE_RC_SUBR=		${PORTNAME}
ZOPE_USER?=		www
ZOPEINSTANCEBASE?=	${PREFIX}/www/Zope213
ZOPEINSTANCEDIR?=	${ZOPEINSTANCEBASE}/${ZOPEINSTANCENAME}

post-patch:
	@${REINPLACE_CMD} -e 's/#.*effective-user chrism/effective-user ${ZOPE_USER}/' \
		${WRKSRC}/src/Zope2/utilities/skel/etc/zope.conf.in
	@${RM} ${WRKSRC}/src/Zope2/utilities/skel/etc/zope.conf.in.bak
	@${RM} ${WRKSRC}/src/Zope2/Startup/zopectl.py.orig

.include <bsd.port.mk>
