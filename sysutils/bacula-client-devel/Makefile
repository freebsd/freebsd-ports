# New ports collection makefile for:	bacula
# Date created:				5 March 2006
# Whom:					Dan Langille <dan@langille.org>
#
# $FreeBSD$
#


PORTNAME=	bacula
PKGNAMESUFFIX=	-client-devel

MASTERDIR=	${.CURDIR}/../bacula-server-devel

COMMENT=	The network backup solution (client) - DEVELOPMENT Version
PLIST=		${PKGDIR}/pkg-plist.client

WITH_CLIENT_ONLY=	yes
USE_RC_SUBR=   bacula-fd.sh

.include "${MASTERDIR}/Makefile"
