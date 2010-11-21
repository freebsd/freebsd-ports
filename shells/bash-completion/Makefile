# New ports collection makefile for:	bash_completion
# Date created:				29 May 2003
# Whom:					kirk@strauser.com
#
# $FreeBSD$
#

PORTNAME=		bash-completion
PORTVERSION=	1.2
PORTREVISION=	2
PORTEPOCH=		1
CATEGORIES=		shells
MASTER_SITES=	http://bash-completion.alioth.debian.org/files/

MAINTAINER=		adamw@FreeBSD.org
COMMENT=		Programmable completion library for Bash

USE_BZIP2=		yes
SUB_FILES=		pkg-message

RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash
CONFLICTS+=		bash-completion-classic-[0-9]*

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g; \
		s|/etc/bash_completion|${PREFIX}&|g; \
		s|/usr\(/sbin/postconf\)|${PREFIX}\1|g; \
		s|/usr\(/lib/rpm/macros\)|${PREFIX}\1|g; \
		s|/usr/share\(/ssl/openssl.cnf\)|/etc\1|g; \
		s|/usr/ports|${PORTSDIR}|g; \
		s|/usr/lib\(/aspell\)|${PREFIX}/share\1|g; \
		s|/usr/share/info|&:${PREFIX}/info|g; \
		s|\$$(sysconfdir)/profile.d|${PREFIX}/bin|g; \
		s|\(FLAC\)|\1\|flv\|FLV|' \
		${WRKSRC}/bash_completion ${WRKSRC}/Makefile.in ${WRKSRC}/contrib/*

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
