# ex:ts=8
# Ports collection makefile for:  nmap
# Date created:			  Tue Aug 04, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../nmap

PORTNAME=	nmapfe

RUN_DEPENDS=	nmap:${PORTSDIR}/security/nmap

USE_GNOMENG=	yes
USE_GNOME=	gtk12
INSTALL_TARGET=	install-nmapfe
MAN1=		nmapfe.1 xnmap.1

after-install:
	test -e ${PREFIX}/bin/nmapfe \
	    || (cd ${PREFIX}/bin ; ${LN} -f nmapfe xnmap)

.include "${MASTERDIR}/Makefile"
