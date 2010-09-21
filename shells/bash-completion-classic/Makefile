# New ports collection makefile for:	bash_completion
# Date created:				29 May 2003
# Whom:					kirk@strauser.com
#
# $FreeBSD$
#

PORTNAME=	bash-completion-classic
PORTVERSION=	20060301
CATEGORIES=	shells
MASTER_SITES=	http://www.caliban.org/files/bash/ \
		CRITICAL
DISTNAME=	${PORTNAME:C/\-classic//}-${PORTVERSION}

MAINTAINER=	ehaupt@critical.ch
COMMENT=	Programmable completion library for Bash 2.04 and up

WRKSRC=		${WRKDIR}/bash_completion
NO_BUILD=	yes

CONFLICTS=	bash-completion-[0-9]*

SUB_FILES=	pkg-message
PLIST_FILES=	etc/bash_completion

OPTIONS=	GSED	"Use GNU sed to enable additional completions"	off

.include <bsd.port.pre.mk>

RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash

.if defined(WITH_GSED)
RUN_DEPENDS+=	gsed:${PORTSDIR}/textproc/gsed
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g; \
		s|/etc/bash_completion|${PREFIX}&|g; \
		s|/usr\(/sbin/postconf\)|${LOCALBASE}\1|g; \
		s|/usr\(/lib/rpm/macros\)|${LOCALBASE}\1|g; \
		s|/usr/share\(/ssl/openssl.cnf\)|/etc\1|g; \
		s|/usr/ports|${PORTSDIR}|g; \
		s|/usr/lib\(/aspell\)|${LOCALBASE}/share\1|g; \
		s|/usr/share/info|&:${LOCALBASE}/info|g; \
		s|\(FLAC\)|\1\|flv\|FLV|' \
		${WRKSRC}/bash_completion

do-install:
	${INSTALL_DATA} ${WRKSRC}/bash_completion ${PREFIX}/etc

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
