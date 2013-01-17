# Created by:	kirk@strauser.com
#
# $FreeBSD$
#

PORTNAME=	bash-completion
PORTVERSION=	2.0
PORTEPOCH=	1
CATEGORIES=	shells
MASTER_SITES=	http://bash-completion.alioth.debian.org/files/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Programmable completion library for Bash

.if defined(WITH_BASH_DEVEL)
RUN_DEPENDS=bash:${PORTSDIR}/shells/bash-devel
.else
RUN_DEPENDS=bash:${PORTSDIR}/shells/bash
.endif

CONFLICTS=	bash-completion-classic-[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

USE_BZIP2=	yes

SUB_FILES=	pkg-message
SUB_LIST+=	RUNFILE=${DATADIR}/bash_completion.sh
PORTDOCS=	*

.include <bsd.port.options.mk>

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
		s|FLAC|&\|flv\|FLV|; \
		s|\(profiledir = \)${PREFIX}/bin|\1${DATADIR}|g; \
		s|\$$(datadir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/bash_completion ${WRKSRC}/Makefile.in \
		${WRKSRC}/completions/*

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.	for i in README doc/bash_completion.txt doc/bashrc doc/inputrc
		${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.	endfor
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
