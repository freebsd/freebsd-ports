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

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}AccessControl>=2.13.2:security/py-AccessControl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:devel/py-DateTime@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}DocumentTemplate>=0:devel/py-DocumentTemplate@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:devel/py-ExtensionClass@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Missing>=0:devel/py-Missing@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}MultiMapping>=0:devel/py-MultiMapping@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Persistence>=0:devel/py-Persistence@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.OFSP>=2.13.2:devel/py-Products.OFSP@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.ZCatalog>=0:devel/py-Products.ZCatalog@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.ZCTextIndex>=0:devel/py-Products.ZCTextIndex@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Record>=0:devel/py-Record@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}RestrictedPython>=0:security/py-RestrictedPython@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zconfig>=0:devel/py-zconfig@${FLAVOR} \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ZopeUndo>=0:devel/py-ZopeUndo@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0:textproc/py-docutils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}initgroups>=0:devel/py-initgroups@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tempstorage>=0:devel/py-tempstorage@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:devel/py-transaction@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zdaemon>=0:sysutils/py-zdaemon@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zExceptions>=0:devel/py-zExceptions@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zLOG>=0:devel/py-zLOG@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browser>=0:devel/py-zope.browser@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browsermenu>=0:devel/py-zope.browsermenu@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browserpage>=0:devel/py-zope.browserpage@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browserresource>=0:devel/py-zope.browserresource@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:devel/py-zope.configuration@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.container>=0:devel/py-zope.container@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.contentprovider>=0:devel/py-zope.contentprovider@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.contenttype>=0:devel/py-zope.contenttype@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.deferredimport>=0:devel/py-zope.deferredimport@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:devel/py-zope.event@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.exceptions>=0:devel/py-zope.exceptions@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>=0:devel/py-zope.lifecycleevent@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:devel/py-zope.location@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.pagetemplate>=0:devel/py-zope.pagetemplate@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.processlifetime>=0:devel/py-zope.processlifetime@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.proxy>=0:net/py-zope.proxy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.ptresource>=0:devel/py-zope.ptresource@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:security/py-zope.security@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.sendmail>=0:mail/py-zope.sendmail@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.sequencesort>=0:devel/py-zope.sequencesort@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:devel/py-zope.site@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.size>=0:devel/py-zope.size@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.structuredtext>=0:textproc/py-zope.structuredtext@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.tal>=0:textproc/py-zope.tal@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.tales>=3.5.0:devel/py-zope.tales@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.testbrowser>=0:devel/py-zope.testbrowser@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=0:devel/py-zope.testing@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:devel/py-zope.traversing@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.viewlet>=0:devel/py-zope.viewlet@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.BTreeFolder2>=0:devel/py-Products.BTreeFolder2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.ExternalMethod>=0:devel/py-Products.ExternalMethod@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.MailHost>=0:mail/py-Products.MailHost@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.MIMETools>=0:devel/py-Products.MIMETools@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.PythonScripts>=0:devel/py-Products.PythonScripts@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.StandardCacheManagers>=0:devel/py-Products.StandardCacheManagers@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}manuel>=0:devel/py-manuel@${FLAVOR}

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
