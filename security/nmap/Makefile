# ex:ts=8
# Ports collection makefile for:  nmap
# Date created:			  Tue Aug 04, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME?=	nmap
PORTVERSION=	3.30
CATEGORIES=	security ipv6
MASTER_SITES=	http://download.insecure.org/nmap/dist/
DISTNAME=	nmap-${PORTVERSION:S/.b/BETA/}

MAINTAINER=	dominic.marks@btinternet.com
COMMENT?=	Port scanning utility for large networks

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-localdirs
USE_BZIP2=	yes

MAN1?=		nmap.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300004
CFLAGS+=	-DDLT_RAW=12 # for obsoleted <net/bpf.h>
.endif

CONFIGURE_TARGET=	-build=${ARCH}-portbld-freebsd${OSREL}
.if ${PORTNAME} == "nmap"
CONFIGURE_ARGS+=	--without-nmapfe
.endif
ALL_TARGET?=		nmap
INSTALL_TARGET?=	install-nmap

.if !target(post-install) && (${PORTNAME} == "nmap")
post-install:
	@strip ${PREFIX}/bin/nmap
.endif

.include <bsd.port.post.mk>
