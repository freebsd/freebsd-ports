# New ports collection makefile for:	samba-libsmbclient
# Date created:				23 Juli 2003
# Whom:					Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTREVISION=		0
PORTEPOCH=		0
PKGNAMESUFFIX=		-libsmbclient

COMMENT=		Shared libs from the samba package

CONFLICTS=

SAMBA_PORT?=		samba3
SAMBA_SUBPORT=		yes

MASTERDIR=		${.CURDIR}/../${SAMBA_PORT}
PKGDIR=			${.CURDIR}

USE_LDCONFIG=		yes

OPTIONS=		ADS		"With Active Directory support" off \
			ADDNS		"Build the libaddns shared library" off \
			SHAREMODES	"Build the libsharemodes shared library" off

.include "${MASTERDIR}/Makefile"
