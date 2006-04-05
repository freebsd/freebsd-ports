# New ports collection makefile for:	Zope 3
# Date created:				Thu Sep 22 14:26:16 MSD 2005
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	zope
PORTVERSION=	3.2.1
CATEGORIES=	www python zope
MASTER_SITES=	http://www.zope.org/Products/Zope3/${PORTVERSION}/
DISTNAME=	Zope-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	zope

MAINTAINER=	dsh@vlink.ru
COMMENT=	An object-based web application platform

LATEST_LINK=	zope3
USE_PYTHON=	yes
USE_RC_SUBR=	${PORTNAME}3.sh zeo3.sh

# Note: the notes that follow reflect the decisions of prior maintainers
# of this port. IOW, don't blame me if you don't like the way it's done.
# Exceptions to this are marked as such.

# Change these, if you like, via the environment.
WEBBASEDIR?=		www
SZOPEBASEDIR?=		${WEBBASEDIR}/Zope3

# Do not change anything below this line.

ZOPEBASEDIR=	${PREFIX}/${SZOPEBASEDIR}

ALL_TARGET=	# empty
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--force --prefix=${ZOPEBASEDIR} \
		--with-python=${PYTHON_CMD}

PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB=	ZOPEBASEDIR=${SZOPEBASEDIR}
SUB_FILES=	pkg-message
SUB_LIST=	ZOPEBASEDIR=${ZOPEBASEDIR}

post-patch:
.for i in zdaemon zope
	@${RM} -f ${WRKSRC}/Zope/zopeskel/etc/${i}.conf.in.orig
.endfor

post-install:
	@${FIND} ${ZOPEBASEDIR} -type f -print0 | ${XARGS} -0 -- ${CHMOD} a-w
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
