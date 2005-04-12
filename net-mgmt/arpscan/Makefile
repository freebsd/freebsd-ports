# New ports collection makefile for:	arpscan
# Date created:				22 Mar 2004
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	arpscan
PORTVERSION=	0.2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://ish.cx/~jason/arpscan/

MAINTAINER=	dyeske@yahoo.com
COMMENT=	Simple arp scanner

BUILD_DEPENDS=	${LOCALBASE}/lib/libdnet.a:${PORTSDIR}/net/libdnet

BROKEN=		Unfetchable

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PLIST_FILES=	bin/arpscan

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 500000
IGNORE=		"unknown BIOCSETIF error"
.endif

.include <bsd.port.post.mk>
