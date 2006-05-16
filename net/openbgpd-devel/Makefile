# New ports collection makefile for:	openbgpd-devel
# Date created:				Mar 15 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openbgpd-devel
PORTVERSION=	${SNAPSHOT}
PORTREVISION=	0
CATEGORIES=	net
DISTFILES=	${PORTNAME}-${PORTVERSION}.tgz:freebsd \
		hash.h:freebsd strtonum.c:freebsd
SNAPSHOT=	20060516

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Free implementation of the Border Gateway Protocol, Version 4

CONFLICTS=	zebra-0* quagga-0* openbgpd-devel-*

MASTERDIR=	${.CURDIR}/../openbgpd
MD5_FILE=	${.CURDIR}/distinfo

EXTRA_PATCHES=	${.CURDIR}/files/devel-bgpd_bgpd.8 \
		${.CURDIR}/files/devel-bgpd_kroute.c \
		${.CURDIR}/files/devel-bgpctl_bgpctl.c \
		${.CURDIR}/files/devel-bgpctl_parser.c

COPTS+=		-DRTA_LABEL=0

.include "${MASTERDIR}/Makefile"
