# New ports collection makefile for:	Zope
# Date created:         Sat 21 Aug 1999
# Whom:                 Peter Cornelius <pcc@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	zope
PORTVERSION=	2.7.0
CATEGORIES=	www python zope
MASTER_SITES=	http://www.zope.org/Products/Zope/${PORTVERSION}/${PORTVERSION}/
DISTNAME=	Zope-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	estartu@augusta.de
COMMENT=	An object-based web application platform

BUILD_DEPENDS+=	${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/_xmlplus/sax/expatreader.py:${PORTSDIR}/textproc/py-xml

USE_PYTHON=	yes
DIST_SUBDIR=	zope

# Note: the notes that follow reflect the decisions of prior maintainers
# of this port. IOW, don't blame me if you don't like the way it's done.
# Exceptions to this are marked as such.

# Build has to be done in the final location after installing the sources
# there. It was a major action to fix all paths otherwise.

# Change these, if you like, via the environment.
WEBBASEDIR?=		www
SZOPEBASEDIR?=		${WEBBASEDIR}/Zope
SCGIBINDIR?=		${WEBBASEDIR}/cgi-bin
SAPACHE_CONFDIR?=	etc/apache
ZOPE_USER?=		www

# Do not change anything below this line.

ZOPEBASEDIR=	${PREFIX}/${SZOPEBASEDIR}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${ZOPEBASEDIR}

USE_GMAKE=	yes
ALL_TARGET=	build
MAKEFILE=	makefile

PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR}

.if defined(BATCH)
ISBATCH=	-u admin:test123
.else
ISBATCH=	""
.endif

post-install:
	@${MV} ${PREFIX}/${SZOPEBASEDIR}/skel/etc/zope.conf.in ${PREFIX}/${SZOPEBASEDIR}/skel/etc/zope.conf.sample.in
	@${SED} -e "s|%%ZOPEBASEDIR%%|${ZOPEBASEDIR}|g" < pkg-message

instance:
	@${PREFIX}/${SZOPEBASEDIR}/bin/mkzopeinstance.py -d ${ZOPEBASEDIR} ${ISBATCH}
	@${CAT} ${FILESDIR}/zope.conf_changes | \
		${SED} "s/@@@ZOPE_USER@@@/${ZOPE_USER}/g" | \
		${PATCH} ${ZOPEBASEDIR}/etc/zope.conf.sample
	@${RM} ${ZOPEBASEDIR}/etc/zope.conf.sample.orig
	@${CHOWN} ${ZOPE_USER} ${ZOPEBASEDIR}/var
	@${CHOWN} ${ZOPE_USER} ${ZOPEBASEDIR}/log
	@${SED} -e "s|%%ZOPEBASEDIR%%|${ZOPEBASEDIR}|g"  < ${FILESDIR}/zope.sh.in > ${PREFIX}/etc/rc.d/zope.sh.sample

.include <bsd.port.mk>
