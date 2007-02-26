# New ports collection makefile for:	turbogears
# Date created:		2006-01-08
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	TurboGears
PORTVERSION=	1.0.1
CATEGORIES=	www python
MASTER_SITES=	http://files.turbogears.org/eggs/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=
DISTFILES=	${PYTURBOGEARS_EGG}
DISTFILES+=	${TGDEPEGGS}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python-Based Framework for Rapid Web Development

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}
# ${PYTHON_PKGNAMEPREFIX} is safe here, because we USE_PYTHON 2.4
RUN_DEPENDS+=	kid:${PORTSDIR}/devel/py-kid \
		paster:${PORTSDIR}/www/py-pastescript \
		${PYTHON_PKGNAMEPREFIX}simplejson>=1.4:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}cheetah>=2.0.r7:${PORTSDIR}/devel/py-cheetah \
		${PYTHON_PKGNAMEPREFIX}formencode>=0.6_1:${PORTSDIR}/www/py-formencode \
		${PYTHON_PKGNAMEPREFIX}Paste>=1.1.1:${PORTSDIR}/www/py-paste \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.1:${PORTSDIR}/www/py-pastedeploy \
		${PYTHON_PKGNAMEPREFIX}PyProtocols>=1.0.a0.r2082:${PORTSDIR}/devel/py-protocols-devel \
		${PYTHON_PKGNAMEPREFIX}RuleDispatch>=0.5.a0.r2115:${PORTSDIR}/devel/py-ruledispatch \
		${PYTHON_PKGNAMEPREFIX}sqlobject>=0.7.2:${PORTSDIR}/databases/py-sqlobject \
		${PYTHON_PKGNAMEPREFIX}TurboCheetah>=0.9.5:${PORTSDIR}/devel/py-turbocheetah \
		${PYTHON_PKGNAMEPREFIX}TurboJson>=1.0:${PORTSDIR}/devel/py-turbojson \
		${PYTHON_PKGNAMEPREFIX}TurboKid>=0.9.9:${PORTSDIR}/devel/py-turbokid

USE_GETTEXT=	yes
USE_PYTHON=	2.4

# Some dependencies have specific platform information in their filename
MANUAL_PACKAGE_BUILD=Doesn't build in tinderbox environment

# see EGG-INFO/requires.txt, EGG-INFO/extras.txt
OPTIONS=	GENSHI		"Use Genshi TG[future])" off \
		NOSE		"Use nose TG[testtools]" off \
		PYSQLITE	"Use pysqlite TG[testtools]" on \
		SQLALCHEMY	"Use SQLAlchemy TG[future, testtools]" off \
		TGFASTDATA	"Use TGFastData TG[exp]" off

PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S|${PREFIX}/||} \
		EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		EGG="${PORTNAME}==${PORTVERSION} ${REG_TGDEPEGGS}"

EASY_INSTALL_CMD?=	${LOCALBASE}/bin/easy_install-${PYTHON_VER}
EASY_INSTALL_ARGS=	-b ${WRKSRC} -N
EASY_INSTALL_DEPS_ARGS=	${EASY_INSTALL_ARGS}

DATADIR=	${PYTHON_SITELIBDIR}/${PYTURBOGEARS_EGG}

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

PYTURBOGEARS_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

# We are waiting for the following ports use Python eggs:
#    devel/py-celementtree
#    devel/py-configobj
#    devel/py-elementtree
#    www/py-cheerypy
# When it happens, we shall remove the respective entry from TGDEPEGGS,
# REG_TGDEPEGGS, distinfo, and add the dependent port to RUN_DEPENDS
OSRELEASE!=	${DESTDIR}/usr/bin/uname -r
ENVINFO=	py${PYTHON_VER}-${OPSYS:L}-${OSRELEASE}-${ARCH}.egg

TGDEPEGGS=	CherryPy-2.2.1-py2.4.egg cElementTree-1.0.5-20051216.tar.gz \
		configobj-4.3.2-py2.4.egg elementtree-1.2.6-py2.4.egg
REG_TGDEPEGGS=	CherryPy==2.2.1 cElementTree==1.0.5-20051216 \
		configobj==4.3.2 elementtree==1.2.6
PLIST_SUB+=	PYCHERRYPY_EGG=CherryPy-2.2.1-py2.4.egg \
		PYCONFIGOBJ_EGG=configobj-4.3.2-py2.4.egg \
		PYELEMENTTREE_EGG=elementtree-1.2.6-py2.4.egg \
		PYCELEMENTTREE_EGG=cElementTree-1.0.5_20051216-${ENVINFO}
#

do-extract:
	@${MKDIR} ${WRKSRC}

do-build:
	@${DO_NADA}

do-install:
	@cd ${WRKSRC}; \
	for FILE in ${TGDEPEGGS}; do \
	    ${EASY_INSTALL_CMD} ${EASY_INSTALL_DEPS_ARGS} ${DISTDIR}/$${FILE}; \
	done; \
	${EASY_INSTALL_CMD} ${EASY_INSTALL_ARGS} ${DISTDIR}/${PYTURBOGEARS_EGG}

.include <bsd.port.pre.mk>

# OPTIONS
.if defined (WITH_GENSHI)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Genshi>=0.3.6:${PORTSDIR}/textproc/py-genshi
.endif

.if defined (WITH_NOSE)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}nose>=0.9.1:${PORTSDIR}/devel/py-nose
.endif

.if defined (WITH_PYSQLITE)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pysqlite>=2.0.7_1:${PORTSDIR}/databases/py-pysqlite23
.endif

.if defined (WITH_SQLALCHEMY)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.3.4:${PORTSDIR}/databases/py-sqlalchemy
.endif

PYTGFASTDATA_EGG=	TGFastData-0.9a6-py2.4.egg
.if defined (WITH_TGFASTDATA)
TGDEPEGGS+=	${PYTGFASTDATA_EGG}
REG_TGDEPEGGS+=	TGFastData==0.9a6
WITHTGFASTDATA=	""
.else
WITHTGFASTDATA=	"@comment "
.endif
PLIST_SUB+=	WITHTGFASTDATA=${WITHTGFASTDATA} PYTGFASTDATA_EGG=${PYTGFASTDATA_EGG}
# end OPTIONS

.include <bsd.port.post.mk>
