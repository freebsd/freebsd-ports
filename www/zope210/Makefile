# New ports collection makefile for:	Zope
# Date created:         Sat 21 Aug 1999
# Whom:                 Peter Cornelius <pcc@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	zope
PORTVERSION=	2.7.2
CATEGORIES=	www python zope
MASTER_SITES=	http://www.zope.org/Products/Zope/${PORTVERSION}/
DISTNAME=	Zope-${PORTVERSION}-0
EXTRACT_SUFX=	.tgz

MAINTAINER=	estartu@augusta.de
COMMENT=	An object-based web application platform

BUILD_DEPENDS+=	${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/_xmlplus/sax/expatreader.py:${PORTSDIR}/textproc/py-xml

USE_PYTHON=	yes
USE_RC_SUBR=	yes
USE_REINPLACE=	yes
DIST_SUBDIR=	zope

# Note: the notes that follow reflect the decisions of prior maintainers
# of this port. IOW, don't blame me if you don't like the way it's done.
# Exceptions to this are marked as such.

# Change these, if you like, via the environment.
ZOPE_USER?=		www
WEBBASEDIR?=		www
SZOPEBASEDIR?=		${WEBBASEDIR}/Zope

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

PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR}
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR}
CONFIG_SUB=	ZOPEBASEDIR=${ZOPEBASEDIR} \
		ZOPE_USER=${ZOPE_USER} \
		ZOPEINSTANCEDIR=${ZOPEINSTANCEDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

.if defined(BATCH)
ISBATCH=	-u admin:test123
.else
ISBATCH=	""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,^\(ACCEPTABLE="\)\(.*"\)$$,\1 2.3.4 \2,g' \
		${WRKSRC}/configure

post-install:
	@${MV} ${ZOPEBASEDIR}/skel/etc/zope.conf.in ${ZOPEBASEDIR}/skel/etc/zope.conf.sample.in
	@${SED} ${CONFIG_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} < ${FILESDIR}/pkg-message.in \
		> ${PKGMESSAGE}
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/zope.sh > ${PREFIX}/etc/rc.d/zope.sh
	@${CHMOD} ${BINMODE} ${PREFIX}/etc/rc.d/zope.sh
	@${MKDIR} ${ZOPEBASEDIR}/Products
	@${CP} ${FILESDIR}/Products_00readme-freebsd.txt ${ZOPEBASEDIR}/Products/00readme-freebsd.txt
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

instance:
	@${ZOPEBASEDIR}/bin/mkzopeinstance.py -d ${ZOPEINSTANCEDIR} ${ISBATCH}
	@${SED} ${CONFIG_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} ${FILESDIR}/zope.conf_changes | \
		${PATCH} ${ZOPEINSTANCEDIR}/etc/zope.conf.sample
	@${RM} ${ZOPEINSTANCEDIR}/etc/zope.conf.sample.orig
	@${CHOWN} ${ZOPE_USER} ${ZOPEINSTANCEDIR}/var
	@${CHOWN} ${ZOPE_USER} ${ZOPEINSTANCEDIR}/log
	@${SED} ${CONFIG_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} ${FILESDIR}/instance_message
	@${RM} -f ${ZOPEBASEDIR}/bin/copyzopeskel.pyc

pre-package:
	@${SED} ${CONFIG_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} < ${FILESDIR}/pkg-message.package.in \
		> ${PKGMESSAGE}

.include <bsd.port.mk>
