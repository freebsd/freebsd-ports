# New ports collection makefile for:	portmaster
# Date created:				20 February 2006
# Whom:					Doug Barton <dougb@FreeBSD.org>
#
# $FreeBSD$
#
# This port is self contained in the files directory.
#

PORTNAME=	portmaster
PORTVERSION=	2.15
CATEGORIES=	ports-mgmt
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	Manage your ports without external databases or languages

OPTIONS=	BASH "Install programmable completions for Bash" off \
		ZSH "Install programmable completions for zsh" off

NO_BUILD=	yes
SUB_FILES=	portmaster.sh

PLIST_FILES=	sbin/portmaster

MAN8=		portmaster.8

.include <bsd.port.pre.mk>

.if defined(WITH_BASH)
PLIST_FILES+=	share/portmaster/bash-completions
PLIST_DIRS+=	share/portmaster
.endif

.if defined(WITH_ZSH)
PLIST_FILES+=	share/zsh/site-functions/_portmaster
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/portmaster.sh ${PREFIX}/sbin/portmaster
	${INSTALL_MAN} ${FILESDIR}/portmaster.8 ${MAN8PREFIX}/man/man8

post-install:
.if defined(WITH_BASH)
	${MKDIR} ${PREFIX}/share/portmaster
	${INSTALL_DATA} ${FILESDIR}/bash-completions ${PREFIX}/share/portmaster
.endif
.if defined(WITH_ZSH)
	${MKDIR} ${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${FILESDIR}/zsh-completions \
		${PREFIX}/share/zsh/site-functions/_portmaster
.endif

.include <bsd.port.post.mk>
