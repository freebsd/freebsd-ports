# Created by: kirk@strauser.com
# $FreeBSD$

PORTNAME=		bash-completion
PORTVERSION=	2.1
PORTREVISION=	1
PORTEPOCH=		1
CATEGORIES=		shells
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	adamw

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Programmable completion library for Bash

OPTIONS_DEFINE=		BASH_DEVEL
BASH_DEVEL_DESC=	Use shells/bash-devel instead of shells/bash

CONFLICTS=	bash-completion-classic-[0-9]*

USE_BZIP2=		yes
USE_AUTOTOOLS=	aclocal automake
GNU_CONFIGURE=	yes
USES=			gmake

SUB_FILES=	pkg-message
SUB_LIST+=	RUNFILE=${DATADIR}/bash_completion.sh

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBASH_DEVEL}
RUN_DEPENDS=bash:${PORTSDIR}/shells/bash-devel
.else
RUN_DEPENDS=bash:${PORTSDIR}/shells/bash
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|FLAC|&\|flv\|FLV|;' ${WRKSRC}/bash_completion

post-configure:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g; \
		s|/etc/bash_completion|${PREFIX}&|g; \
		s|/usr\(/sbin/postconf\)|${PREFIX}\1|g; \
		s|/usr\(/lib/rpm/macros\)|${PREFIX}\1|g; \
		s|/usr/share\(/ssl/openssl.cnf\)|/etc\1|g; \
		s|/usr/ports|${PORTSDIR}|g; \
		s|/usr/lib\(/aspell\)|${PREFIX}/share\1|g; \
		s|/usr/share/info|&:${PREFIX}/info|g;' \
		${WRKSRC}/completions/*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README doc/bash_completion.txt doc/bashrc doc/inputrc
		${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
