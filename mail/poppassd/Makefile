# New ports collection makefile for:	poppassd
# Date Created:	21 August 1996
# Whom:	Andrew Stevenson <andrew@ugh.net.au> based heavily on the changes by Stephen Melvin <melvin@zytek.com>
#
# $FreeBSD$
#

PORTNAME=	poppassd
PORTVERSION=	4.0
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.qualcomm.com/eudora/servers/unix/password/
DISTNAME=	pwserve-4

MAINTAINER=	andrew@ugh.net.au

EXTRACT_CMD=	/bin/cat
EXTRACT_SUFX=	
EXTRACT_BEFORE_ARGS=	
EXTRACT_AFTER_ARGS=	| ${SED} -e '1,16d' | ${SH}
WRKSRC=			${WRKDIR}/poppassd
ALL_TARGET=	poppassd
MAN8=		poppassd.8

post-install:
	@ strip ${PREFIX}/libexec/poppassd
	@ ${INSTALL_MAN} ${FILESDIR}/poppassd.8 ${PREFIX}/man/man8/

.include <bsd.port.mk>
