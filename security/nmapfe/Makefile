# ex:ts=8
# Ports collection makefile for:  nmap
# Date created:			  Tue Aug 04, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	nmapfe

COMMENT=	GUI frontend for the nmap scanning utility

RUN_DEPENDS=	nmap:${PORTSDIR}/security/nmap

MASTERDIR=	${.CURDIR}/../nmap
PLIST=		${.CURDIR}/pkg-plist

USE_GNOME=	gtk12

MAN1=		nmapfe.1 xnmap.1

ALL_TARGET=	nbase/libnbase.a nmapfe/nmapfe
INSTALL_TARGET=	install-nmapfe

.include "${MASTERDIR}/Makefile"
