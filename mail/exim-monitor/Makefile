# Created by: sheldonh@FreeBSD.org
# $FreeBSD$

PKGNAMESUFFIX=	-monitor

COMMENT=	The Exim monitor for the Exim MTA

MASTERDIR=	${.CURDIR}/../exim

EXIMON_ONLY=	yes
OPTIONS_SLAVE=	EXIMON

# This dependency is disabled, because it prevents package users from
# using the exim-monitor package with any of the exim slave packages.
#
#RUN_DEPENDS=	${LOCALBASE}/sbin/exim:mail/exim

.include "${MASTERDIR}/Makefile"
