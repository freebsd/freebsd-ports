# New ports collection makefile for:	py-miniupnpc
# Date created:				9 Aug 2009
# Whom:					Anonymous
#
# $FreeBSD$
#

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python module for miniupnpc

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/miniupnpc:build

MASTERDIR=	${.CURDIR}/../miniupnpc

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

WRKDIR=		${WRKDIRPREFIX}${MASTERDIR}/work
PLIST=		${.CURDIR}/pkg-plist

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
