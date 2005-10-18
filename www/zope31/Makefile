# New ports collection makefile for:	Zope-3.1.x
# Date created:				Thu Sep 22 14:26:16 MSD 2005
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	zope
PORTVERSION=	3.1.0
CATEGORIES=	www python zope
MASTER_SITES=	http://www.zope.org/Products/Zope3/${PORTVERSION}final/
DISTNAME=	Zope-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	zope

MAINTAINER=	dsh@vlink.ru
COMMENT=	An object-based web application platform

USE_PYTHON=	yes
USE_RC_SUBR=	${PORTNAME}31.sh zeo31.sh

# Note: the notes that follow reflect the decisions of prior maintainers
# of this port. IOW, don't blame me if you don't like the way it's done.
# Exceptions to this are marked as such.

# Change these, if you like, via the environment.
WEBBASEDIR?=		www
SZOPEBASEDIR?=		${WEBBASEDIR}/Zope31

# Do not change anything below this line.

ZOPEBASEDIR=		${PREFIX}/${SZOPEBASEDIR}

ALL_TARGET=
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${ZOPEBASEDIR} --force

PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR}
SUB_FILES=	pkg-message
SUB_LIST=	ZOPEBASEDIR=${ZOPEBASEDIR}

post-patch:
.for i in zdaemon zope
	${RM} -f ${WRKSRC}/Zope/zopeskel/etc/${i}.conf.in.orig
.endfor

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}31.sh ${WRKDIR}/zeo31.sh \
		${PREFIX}/etc/rc.d
	${FIND} ${ZOPEBASEDIR} -type f -print0 | ${XARGS} -0 -- ${CHMOD} a-w

	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
