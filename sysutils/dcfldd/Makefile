# New ports collection makefile for:   dcfldd
# Date created:        09 January 2005
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dcfldd
PORTVERSION=	1.2.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dcfldd

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	An enhanced dd tool with MD5 hashing capability

USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
MAN1=		dcfldd.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-dcfldd.h ${PATCHDIR}/extra-patch-human.c \
		${PATCHDIR}/extra-patch-xstrtol.h
.endif

.include <bsd.port.post.mk>
