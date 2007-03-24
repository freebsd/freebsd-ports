# New ports collection makefile for:	Zope-2.8.x
# Date created:				Tue Sep 13 11:34:24 MSD 2005
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	zope
PORTVERSION=	2.8.8
PORTREVISION=	2
CATEGORIES=	www python zope
MASTER_SITES=	http://www.zope.org/Products/Zope/${PORTVERSION}/:src \
		http://www.zope.org/Products/Zope/Hotfix-2006-08-21/Hotfix-20060821/:hotfix1 \
		http://www.zope.org/Products/Zope/Hotfix-2007-03-20/Hotfix-20070320/:hotfix2
DISTFILES=	Zope-${PORTVERSION}-final.tgz:src \
		${HOTFIX1}.tar.gz:hotfix1 \
		${HOTFIX2}.tgz:hotfix2
DIST_SUBDIR=	zope

MAINTAINER=	dsh@vlink.ru
COMMENT=	An object-based web application platform

WRKSRC=		${WRKDIR}/Zope-${PORTVERSION}-final
USE_PYTHON=	2.3-2.4
USE_RC_SUBR=	${PORTNAME}28.sh zeo28.sh
HOTFIX1=	Hotfix_20060821
HOTFIX2=	Hotfix_20070320
LATEST_LINK=	zope28

# Note: the notes that follow reflect the decisions of prior maintainers
# of this port. IOW, don't blame me if you don't like the way it's done.
# Exceptions to this are marked as such.

# Change these, if you like, via the environment.
ZOPE_USER?=		www
WEBBASEDIR?=		www
SZOPEBASEDIR?=		${WEBBASEDIR}/Zope28

# Do not change anything below this line.

.if defined(INSTANCENAME)
ZOPEINSTANCENAME=	${INSTANCENAME}
.endif

ZOPEBASEDIR=		${PREFIX}/${SZOPEBASEDIR}
ZOPEINSTANCEBASE?=	${PREFIX}/${SZOPEBASEDIR}
ZOPEINSTANCEDIR?=	${ZOPEINSTANCEBASE}/${ZOPEINSTANCENAME}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${ZOPEBASEDIR}

USE_GMAKE=	yes
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
	${REINPLACE_CMD} \
		-e 's,^\(ACCEPTABLE="\).*"$$,\1${PYTHON_PORTVERSION}",g' \
		-e 's,^\(TARGET="\).*"$$,\1${PYTHON_PORTVERSION}",g' \
		-e 's,^\(EXENAMES="\).*"$$,\1${PYTHON_VERSION}",g' \
		${WRKSRC}/configure

post-build:
	-${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKDIR}/${HOTFIX1}
	-${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKDIR}/${HOTFIX2}

post-install:
	@${CP} -R ${WRKDIR}/${HOTFIX1} ${ZOPEBASEDIR}/lib/python/Products/
	@${CP} -R ${WRKDIR}/${HOTFIX2} ${ZOPEBASEDIR}/lib/python/Products/
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
