# New ports collection makefile for:	GNU colorized `ls'
# Date created:				06 January 1996
# Whom:					bmc@WillsCreek.COM
#
# $FreeBSD$
#

PORTNAME=	gnuls
PORTVERSION=	4.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	fileutils
DISTNAME=	fileutils-${PORTVERSION}

MAINTAINER=	bmc@WillsCreek.COM

GNU_CONFIGURE=	yes
MAN1=		gnuls.1 dircolors.1 dir.1 vdir.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500019
.if defined(WITH_ACL_SUPPORT)
PATCHFILES=	gnuls-acl-20010825.patch
PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR= jedgar
.else
pre-fetch:
	@${ECHO} "To build this port with ACL support, define"
	@${ECHO} "WITH_ACL_SUPPORT (i.e. make -DWITH_ACL_SUPPORT)"
.endif
.endif

.include <bsd.port.post.mk>
