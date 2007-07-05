# New ports collection makefile for:	arpscan
# Date created:				22 Mar 2004
# Whom:					David Yeske <dyeske@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	arpscan
PORTVERSION=	0.3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://ish.cx/~jason/arpscan/ \
		http://unx.ca/~jason/arpscan/

MAINTAINER=	dyeske@gmail.com
COMMENT=	Simple arp scanner

LIB_DEPENDS=	dnet.1:${PORTSDIR}/net/libdnet

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		 --with-libdnet=${LOCALBASE}

PLIST_FILES=	bin/arpscan

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 500000
IGNORE=		unknown BIOCSETIF error
.endif

.include <bsd.port.post.mk>
