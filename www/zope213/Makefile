# New ports collection makefile for:	Zope-2.9.x
# Date created:				Mon Jan 10 14:40:00 JST 2006
# Whom:					Yasushi Hayashi <yasi@yasi.to>
#
# $FreeBSD$
#

PORTNAME=	zope
PORTVERSION=	2.9.3
CATEGORIES=	www python zope
MASTER_SITES=	http://www.zope.org/Products/Zope/${PORTVERSION}/
DISTNAME=	Zope-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	zope

MAINTAINER=	yasi@yasi.to
COMMENT=	An object-based web application platform

USE_PYTHON=	yes
USE_RC_SUBR=	${PORTNAME}29.sh zeo29.sh
LATEST_LINK=	zope29

# Note: the notes that follow reflect the decisions of prior maintainers
# of this port. IOW, don't blame me if you don't like the way it's done.
# Exceptions to this are marked as such.

# Change these, if you like, via the environment.
ZOPE_USER?=		www
WEBBASEDIR?=		www
SZOPEBASEDIR?=		${WEBBASEDIR}/Zope29

# Do not change anything below this line.

.if defined(INSTANCENAME)
ZOPEINSTANCENAME=	${INSTANCENAME}
.endif

ZOPEBASEDIR=		${PREFIX}/${SZOPEBASEDIR}
ZOPEINSTANCEBASE?=	${PREFIX}/${SZOPEBASEDIR}
ZOPEINSTANCEDIR?=	${ZOPEINSTANCEBASE}/${ZOPEINSTANCENAME}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${ZOPEBASEDIR} --force

USE_GMAKE=	yes
ALL_TARGET=	build

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

post-install:
	${MV} ${ZOPEBASEDIR}/skel/etc/zope.conf.in \
		${ZOPEBASEDIR}/skel/etc/zope.conf.sample.in

	${MKDIR} ${ZOPEBASEDIR}/Products
	${CP} ${FILESDIR}/Products_00readme-freebsd.txt \
		${ZOPEBASEDIR}/Products/00readme-freebsd.txt

	${FIND} ${ZOPEBASEDIR} -type f -print0 | ${XARGS} -0 -- ${CHMOD} a-w

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
	${CP} ${WRKDIR}/package-pkg-message ${PKGMESSAGE}

.include <bsd.port.mk>
