# $FreeBSD$

PORTNAME=	zope213
PORTVERSION=	2.13.24
CATEGORIES=	www python zope
MASTER_SITES=	CHEESESHOP
DISTNAME=	Zope2-${PORTVERSION}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Object-based web application platform Version 2.13

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}AccessControl>=2.13.2:security/py-AccessControl \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:devel/py-DateTime \
		${PYTHON_PKGNAMEPREFIX}DocumentTemplate>=0:devel/py-DocumentTemplate \
		${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:devel/py-ExtensionClass \
		${PYTHON_PKGNAMEPREFIX}Missing>=0:devel/py-Missing \
		${PYTHON_PKGNAMEPREFIX}MultiMapping>=0:devel/py-MultiMapping \
		${PYTHON_PKGNAMEPREFIX}Persistence>=0:devel/py-Persistence \
		${PYTHON_PKGNAMEPREFIX}Products.OFSP>=2.13.2:devel/py-Products.OFSP \
		${PYTHON_PKGNAMEPREFIX}Products.ZCatalog>=0:devel/py-Products.ZCatalog \
		${PYTHON_PKGNAMEPREFIX}Products.ZCTextIndex>=0:devel/py-Products.ZCTextIndex \
		${PYTHON_PKGNAMEPREFIX}Record>=0:devel/py-Record \
		${PYTHON_PKGNAMEPREFIX}RestrictedPython>=0:security/py-RestrictedPython \
		${PYTHON_PKGNAMEPREFIX}zconfig>=0:devel/py-zconfig \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}ZopeUndo>=0:devel/py-ZopeUndo \
		${PYTHON_PKGNAMEPREFIX}docutils>=0:textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}initgroups>=0:devel/py-initgroups \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}tempstorage>=0:devel/py-tempstorage \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:devel/py-transaction \
		${PYTHON_PKGNAMEPREFIX}zdaemon>=0:sysutils/py-zdaemon \
		${PYTHON_PKGNAMEPREFIX}zExceptions>=0:devel/py-zExceptions \
		${PYTHON_PKGNAMEPREFIX}zLOG>=0:devel/py-zLOG \
		${PYTHON_PKGNAMEPREFIX}zope.browser>=0:devel/py-zope.browser \
		${PYTHON_PKGNAMEPREFIX}zope.browsermenu>=0:devel/py-zope.browsermenu \
		${PYTHON_PKGNAMEPREFIX}zope.browserpage>=0:devel/py-zope.browserpage \
		${PYTHON_PKGNAMEPREFIX}zope.browserresource>=0:devel/py-zope.browserresource \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.container>=0:devel/py-zope.container \
		${PYTHON_PKGNAMEPREFIX}zope.contentprovider>=0:devel/py-zope.contentprovider \
		${PYTHON_PKGNAMEPREFIX}zope.contenttype>=0:devel/py-zope.contenttype \
		${PYTHON_PKGNAMEPREFIX}zope.deferredimport>=0:devel/py-zope.deferredimport \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:devel/py-zope.event \
		${PYTHON_PKGNAMEPREFIX}zope.exceptions>=0:devel/py-zope.exceptions \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>=0:devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:devel/py-zope.location \
		${PYTHON_PKGNAMEPREFIX}zope.pagetemplate>=0:devel/py-zope.pagetemplate \
		${PYTHON_PKGNAMEPREFIX}zope.processlifetime>=0:devel/py-zope.processlifetime \
		${PYTHON_PKGNAMEPREFIX}zope.proxy>=0:net/py-zope.proxy \
		${PYTHON_PKGNAMEPREFIX}zope.ptresource>=0:devel/py-zope.ptresource \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:security/py-zope.security \
		${PYTHON_PKGNAMEPREFIX}zope.sendmail>=0:mail/py-zope.sendmail \
		${PYTHON_PKGNAMEPREFIX}zope.sequencesort>=0:devel/py-zope.sequencesort \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:devel/py-zope.site \
		${PYTHON_PKGNAMEPREFIX}zope.size>=0:devel/py-zope.size \
		${PYTHON_PKGNAMEPREFIX}zope.structuredtext>=0:textproc/py-zope.structuredtext \
		${PYTHON_PKGNAMEPREFIX}zope.tal>=0:textproc/py-zope.tal \
		${PYTHON_PKGNAMEPREFIX}zope.tales>=3.5.0:devel/py-zope.tales \
		${PYTHON_PKGNAMEPREFIX}zope.testbrowser>=0:devel/py-zope.testbrowser \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=0:devel/py-zope.testing \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:devel/py-zope.traversing \
		${PYTHON_PKGNAMEPREFIX}zope.viewlet>=0:devel/py-zope.viewlet \
		${PYTHON_PKGNAMEPREFIX}Products.BTreeFolder2>=0:devel/py-Products.BTreeFolder2 \
		${PYTHON_PKGNAMEPREFIX}Products.ExternalMethod>=0:devel/py-Products.ExternalMethod \
		${PYTHON_PKGNAMEPREFIX}Products.MailHost>=0:mail/py-Products.MailHost \
		${PYTHON_PKGNAMEPREFIX}Products.MIMETools>=0:devel/py-Products.MIMETools \
		${PYTHON_PKGNAMEPREFIX}Products.PythonScripts>=0:devel/py-Products.PythonScripts \
		${PYTHON_PKGNAMEPREFIX}Products.StandardCacheManagers>=0:devel/py-Products.StandardCacheManagers \
		${PYTHON_PKGNAMEPREFIX}manuel>=0:devel/py-manuel

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

.include <bsd.port.mk>
