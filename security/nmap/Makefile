# ex:ts=8
# Ports collection makefile for:  nmap
# Date created:			  Tue Aug 04, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME?=	nmap
PORTVERSION=	3.00
CATEGORIES=	security
MASTER_SITES=	http://download.insecure.org/nmap/dist/  \
		http://www.mobis.com/ajax/projects/
DISTNAME=	nmap-${PORTVERSION:S/.b/BETA/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	d.marks@student.umist.ac.uk

.include <bsd.port.pre.mk>

GNU_CONFIGURE=	yes
.if ${OSVERSION} < 300004
CFLAGS+=	-DDLT_RAW=12 # for obsoleted <net/bpf.h>
.endif
MAN1?=		nmap.1

.if !target(post-install) && (${PORTNAME} == "nmap")
post-install:
	@strip ${PREFIX}/bin/nmap
.endif

.include <bsd.port.post.mk>
