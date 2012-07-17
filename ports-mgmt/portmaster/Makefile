# New ports collection makefile for:	portmaster
# Date created:				20 February 2006
# Whom:					Doug Barton <dougb@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	portmaster
PORTVERSION=	3.13.1
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://dougbarton.us/Downloads/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	Manage your ports without external databases or languages

OPTIONS=	BASH "Install programmable completions for Bash" off \
		ZSH "Install programmable completions for zsh" off

PLIST_FILES=	sbin/portmaster etc/portmaster.rc.sample

MAN8=		portmaster.8

.include <bsd.port.pre.mk>

.if defined(WITH_BASH)
PLIST_FILES+=	etc/bash_completion.d/portmaster.sh
PLIST_DIRSTRY+=	etc/bash_completion.d
.endif

.if defined(WITH_ZSH)
PLIST_FILES+=	share/zsh/site-functions/_portmaster
PLIST_DIRSTRY+=	share/zsh/site-functions share/zsh
.endif

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.asc

do-build:
.for file in portmaster.sh portmaster.rc.sample
	${SED} -e 's#/usr/local#${LOCALBASE}#g' ${WRKSRC}/${file}.in \
	    > ${WRKDIR}/${file}
.endfor
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/portmaster.sh ${PREFIX}/sbin/portmaster
	${INSTALL_DATA} ${WRKDIR}/portmaster.rc.sample ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/portmaster.8 ${MAN8PREFIX}/man/man8

post-install:
.if defined(WITH_BASH)
	${MKDIR} ${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/bash-completions \
		${PREFIX}/etc/bash_completion.d/portmaster.sh
.endif
.if defined(WITH_ZSH)
	${MKDIR} ${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/zsh-completions \
		${PREFIX}/share/zsh/site-functions/_portmaster
.endif

.include <bsd.port.post.mk>
