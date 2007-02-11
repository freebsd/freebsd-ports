# Ports collection makefile for:	py-libdnet
# Date created:			Nov 2, 2005
# Whom:	      			thierry@pompo.net
#
# $FreeBSD$
#

COMMENT=	Python module for libdnet

BROKEN=		Incomplete pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2007-04-10

MASTERDIR=	${.CURDIR}/../libdnet

BUILD_PYTHON_MODULE=	yes

NOT_FOR_ARCHS=			ia64
NOT_FOR_ARCHS_REASON_ia64=	fails to build with internal compiler error

.include "${MASTERDIR}/Makefile"
