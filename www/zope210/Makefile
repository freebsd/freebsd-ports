# New ports collection makefile for:	Zope-2.10.x
# Date created:				Mon Nov 28 22:09:00 JST 2006
# Whom:					Yasushi Hayashi <yasi@yasi.to>
#
# $FreeBSD$
#

PORTNAME=	zope210
PORTVERSION=	2.10.8
CATEGORIES=	www python zope
MASTER_SITES=	http://www.zope.org/Products/Zope/${PORTVERSION}/
DISTNAME=	Zope-${PORTVERSION}-final
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	zope

MAINTAINER=	nakaji@jp.FreeBSD.org
COMMENT=	An object-based web application platform

USE_PYTHON=	2.4
USE_RC_SUBR=	${PORTNAME} zeo210

ZOPE_USER?=		www
WEBBASEDIR?=		www
SZOPEBASEDIR?=		${WEBBASEDIR}/Zope210

.if defined(INSTANCENAME)
ZOPEINSTANCENAME=	${INSTANCENAME}
.endif

ZOPEBASEDIR=		${PREFIX}/${SZOPEBASEDIR}
ZOPEINSTANCEBASE?=	${PREFIX}/${SZOPEBASEDIR}
ZOPEINSTANCEDIR?=	${ZOPEINSTANCEBASE}/${ZOPEINSTANCENAME}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${ZOPEBASEDIR}

ALL_TARGET=	build
MAKEFILE=	makefile

PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR}
SUB_FILES=	instance_message package-pkg-message pkg-message zeo_message
SUB_LIST=	ZOPEBASEDIR=${ZOPEBASEDIR} \
		ZOPE_USER=${ZOPE_USER} \
		ZOPEINSTANCEDIR=${ZOPEINSTANCEDIR}

.if defined(BATCH)
ISBATCH=	-u admin:test123
.else
ISBATCH=	""
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -print0 | ${XARGS} -0 -- ${RM}
	@${REINPLACE_CMD} \
		-e 's,^\(ACCEPTABLE="\).*"$$,\1${PYTHON_PORTVERSION}",g' \
		-e 's,^\(TARGET="\).*"$$,\1${PYTHON_PORTVERSION}",g' \
		-e 's,^\(EXENAMES="\).*"$$,\1${PYTHON_VERSION}",g' \
		${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} \
		-e 's,\(--home="\).*",\1${ZOPEBASEDIR}",g' \
		-e 's,^.*LN.*PYTHON.*$$,,g' \
		${WRKSRC}/${MAKEFILE}

post-build:
	-@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/

post-install:
	${MV} ${ZOPEBASEDIR}/skel/etc/zope.conf.in \
		${ZOPEBASEDIR}/skel/etc/zope.conf.sample.in

	${MKDIR} ${ZOPEBASEDIR}/Products
	${INSTALL_DATA} ${FILESDIR}/Products_00readme-freebsd.txt \
		${ZOPEBASEDIR}/Products/00readme-freebsd.txt

.for d in lib bin doc skel Products
	${FIND} ${ZOPEBASEDIR}/$d -type f -print0 | ${XARGS} -0 -- ${CHMOD} a-w+r
.endfor

	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

instance:
	${ZOPEBASEDIR}/bin/mkzopeinstance.py -d ${ZOPEINSTANCEDIR} ${ISBATCH}

	${SED} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/zope.conf_changes \
		| ${PATCH} ${ZOPEINSTANCEDIR}/etc/zope.conf.sample

	${CHOWN} ${ZOPE_USER} ${ZOPEINSTANCEDIR}/var
	${CHOWN} ${ZOPE_USER} ${ZOPEINSTANCEDIR}/log

	${RM} ${ZOPEINSTANCEDIR}/etc/zope.conf.sample.orig
	${RM} -f ${ZOPEBASEDIR}/bin/copyzopeskel.pyc

	@${CAT} ${WRKDIR}/instance_message

zeo:
	${ZOPEBASEDIR}/bin/mkzeoinstance.py ${ZOPEINSTANCEDIR}
	${CHOWN} ${ZOPE_USER} ${ZOPEINSTANCEDIR}/var
	${CHOWN} ${ZOPE_USER} ${ZOPEINSTANCEDIR}/log
	@${CAT} ${WRKDIR}/zeo_message

pre-package:
	${INSTALL_DATA} ${WRKDIR}/package-pkg-message ${PKGMESSAGE}

.include <bsd.port.mk>
