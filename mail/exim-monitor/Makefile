# Created by: sheldonh@FreeBSD.org
# $FreeBSD$

PKGNAMESUFFIX=	-monitor

COMMENT=	The Exim monitor for the Exim MTA

MASTERDIR=	${.CURDIR}/../exim
PKGDIR=		${.CURDIR}

EXIMON_ONLY=	yes

# This dependency is disabled, because it prevents package users from
# using the exim-monitor package with any of the exim slave packages.
#
#RUN_DEPENDS=	${LOCALBASE}/sbin/exim:${PORTSDIR}/mail/exim

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
