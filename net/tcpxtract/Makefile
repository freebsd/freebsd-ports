# New ports collection makefile for:   tcpxtract
# Date created:        3 January 2006
# Whom:                MANTANI Nobutaka <nobutaka@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	tcpxtract
PORTVERSION=	1.0.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nobutaka@freebsd.org
COMMENT=	A tool for extracting files from network traffic

USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
MAN1=		tcpxtract.1

PLIST_FILES=	bin/tcpxtract etc/tcpxtract.conf

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-tcpxtract.c ${PATCHDIR}/extra-patch-sessionlist.c
.endif

.include <bsd.port.post.mk>

