# New ports collection makefile for:	samhain-server
# Date created:				2005-10-31
# Whom:					David Thiel
#
# $FreeBSD$
#

# This port recognizes the following non-boolean tunables:
#
# WITH_RUNAS_USER:
#       Whe building with "WITH_SERVER" defined, the username of the
#       account Yule will run as. Defaults to "yule". If using
#       WITH_GPG, ensure that this user exists and has a pgp
#       keypair before installing.


PKGNAMESUFFIX=	-server

COMMENT=	Log server for the Samhain IDS

WITH_SERVER=	yes

MASTERDIR=	${.CURDIR}/../../security/samhain

.include "${MASTERDIR}/Makefile"
