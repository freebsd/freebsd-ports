# New ports collection makefile for:		NetBSD makefs
# Date created:					17 December 2003
# Whom:						cperciva@daemonology.net
#
# $FreeBSD$
#

PORTNAME=	makefs
PORTVERSION=	20031215
CATEGORIES=	sysutils
MASTER_SITES=	http://www.daemonology.net/makefs/

MAINTAINER=	cperciva@daemonology.net
COMMENT=	Builds FFS images

MAN8=		makefs.8
PLIST_FILES=	sbin/makefs

do-build:
	cd ${WRKSRC} && ${SH} -xe build.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netbsdsrc/tools/makefs/makefs	\
		${PREFIX}/sbin
.if !defined(WITHOUT_MAN)
	${INSTALL_MAN} ${WRKSRC}/netbsdsrc/usr.sbin/makefs/makefs.8	\
		${PREFIX}/man/man8/
.endif

.include <bsd.port.mk>
