# ex:ts=8
# Ports collection makefile for:  nmap
# Date created:			  Tue Aug 04, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME?=	nmap
PORTVERSION=	2.54.b30
CATEGORIES=	security
MASTER_SITES=	http://www.insecure.org/nmap/dist/  \
		ftp://nuxi.ucdavis.edu/pub/misc/  \
		http://www.mobis.com/ajax/projects/
DISTNAME=	nmap-${PORTVERSION:S/.b/BETA/}
EXTRACT_SUFX=	.tgz

#PATCH_SITES=	http://www.mobis.com/ajax/projects/

MAINTAINER=	obrien@FreeBSD.org

.include <bsd.port.pre.mk>

GNU_CONFIGURE=	yes
.if ${OSVERSION} < 300004
CFLAGS+=	-DDLT_RAW=12 # for obsoleted <net/bpf.h>
.endif
MAN1?=		nmap.1

.if !target(post-install)
post-install:
	@strip ${PREFIX}/bin/nmap
.endif

.include <bsd.port.post.mk>
