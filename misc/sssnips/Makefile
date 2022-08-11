PORTNAME=	sssnips
PORTVERSION=	0.05
CATEGORIES=	misc
MASTER_SITES=	http://devel.ringlet.net/files/misc/sssnips/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shell script snippets written by Peter Pentchev

LICENSE=	BSD2CLAUSE

USES=		gmake tar:xz
MAKE_ENV=	BINGRP=wheel MANDIR=${MANPREFIX}/man/man

PLIST_FILES=	${PROGRAMS:S@^@bin/@} \
		${PROGRAMS:S@^@man/man1/@:S@$@.1.gz@}

PROGRAMS=	bigfile csort declean getkey git-ss git-ssnoq git-ssq \
		hostsearch mkv noagent qidiff qpr resock signfiles stun \
		switch-link syspower vcr vcrtty ws

post-patch:
.for i in vcr.1 vcr.sh
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
