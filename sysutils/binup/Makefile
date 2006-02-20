# New ports collection makefile for:	binup
# Date created:		2 November 2005
# Whom:			BSDUpdates <support@bsdupdates.com>
#
# $FreeBSD$
#

PORTNAME=	binup
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	https://bsdupdates.com/binup/version/${PORTVERSION}/
DISTNAME=	binup-${OPSYS}-${OSREL:C/\..*//}-${PORTVERSION}

MAINTAINER=	support@bsdupdates.com
COMMENT=	BSDUpdates system update tool

ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes
USE_BZIP2=	yes

PLIST_FILES=	libexec/binup/bspatch-static libexec/binup/pw-static sbin/binup
PLIST_DIRS=	libexec/binup

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502010 || ${OSVERSION} >= 700000
IGNORE=		does not support ${OPSYS}-${OSREL} at this time
.endif

do-install:
	${MKDIR} ${PREFIX}/libexec/binup
	${INSTALL_PROGRAM} ${WRKSRC}/bspatch-static ${PREFIX}/libexec/binup
	${INSTALL_PROGRAM} ${WRKSRC}/pw-static ${PREFIX}/libexec/binup
	${INSTALL_PROGRAM} ${WRKSRC}/binup ${PREFIX}/sbin

.include <bsd.port.post.mk>
