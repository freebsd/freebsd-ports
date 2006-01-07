# New ports collection makefile for:	samhain-client
# Date created:				2005-10-31
# Whom:					David Thiel
#
# $FreeBSD$
#
#
# This port recognizes the following non-boolean tunables:
#
# WITH_LOG_SERVER, WITH_ALT_LOG_SERVER. When "WITH_CLIENT" is defined,
#       these specify what server the client will fetch configuration
#       and database files from. This can also be defined at runtime.
#

PKGNAMESUFFIX=	-client

COMMENT=	Client daemon for the Samhain IDS

WITH_CLIENT=	yes
NOPORTDOCS=	yes

MASTERDIR=	${.CURDIR}/../../security/samhain

CONFLICTS=	samhain-2*

.include "${MASTERDIR}/Makefile"
