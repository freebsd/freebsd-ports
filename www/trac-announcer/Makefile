# Created by: Eygene Ryabinkin <rea-fbsd@codelabs.ru>
# $FreeBSD$

PORTNAME=	announcer
PORTVERSION=	1.0
CATEGORIES=	www python
MASTER_SITES=	http://dist.codelabs.ru/fbsd/
PKGNAMEPREFIX=	trac-
DISTNAME=	announcerplugin-r${REL}

MAINTAINER=	rea@FreeBSD.org
COMMENT=	A plugin for making user-customizable notifications

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Babel>=0.9:${PORTSDIR}/devel/py-babel
RUN_DEPENDS+=	trac>=0.11:${PORTSDIR}/www/trac

BROKEN=		Try to access network during install phase
USE_PYTHON=	2.5+
USE_ZIP=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	AnnouncerPlugin
PYDISTUTILS_NOEGGINFO=	yes

WRKSRC=		${WRKDIR}/announcerplugin/trunk
REL=		8411
EGG_VER=	0.12_p2.dev

PLIST_SUB+=	PORTVERSION=${PORTVERSION:S/.a/_a/} \
		PYTHONVERSION=${_PYTHON_VERSION}
PLIST_FILES+=	%%PYTHON_SITELIBDIR%%/AnnouncerPlugin-${EGG_VER}-py%%PYTHONVERSION%%.egg

# We must fix file permissions -- ZIP file have 0000 for every file.
# Directory permissions are fine (they aren't stored inside ZIP
# file), but we set them too -- just in case.
post-extract:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${CHMOD} 644
	@${FIND} ${WRKSRC} -type d | ${XARGS} ${CHMOD} 755

# Build phase: create locale stuff
build: configure
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py compile_catalog

.include <bsd.port.mk>
