# New ports collection makefile for:	barnyard-sguil
# Date created:				23 Jan 2006
# Whom:					pauls
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-sguil
COMMENT=	An output system for Snort (patched for sguil)
PORTREVISION=	1

LIB_DEPENDS+=	tcl84.1:${PORTSDIR}/lang/tcl84

MASTERDIR=	${.CURDIR}/../barnyard
PATCHDIR=	${.CURDIR}/files

CONFIGURE_ARGS+=	--enable-tcl --with-tcl=${PREFIX}/lib/tcl8.4

.include "${MASTERDIR}/Makefile"
