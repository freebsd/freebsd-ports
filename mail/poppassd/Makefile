# New ports collection makefile for:	poppassd
# Version required:	4.0
# Date Created:	21 August 1996
# Whom:	Andrew Stevenson <andrew@ugh.net.au> based heavily on the changes by Stephen Melvin <melvin@zytek.com>
#
# $Id: Makefile,v 1.2 1996/11/10 21:32:29 obrien Exp $
#

DISTNAME=	poppassd
PKGNAME=	poppassd-4.0
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.qualcomm.com/quest/unix/servers/password/
DISTFILES=	pwserve-4

MAINTAINER=	andrew@ugh.net.au

EXTRACT_CMD=	/bin/cat
EXTRACT_SUFX=	
EXTRACT_BEFORE_ARGS=	
EXTRACT_AFTER_ARGS=	| /usr/bin/sed -e '1,16d' | /bin/sh
ALL_TARGET=	poppassd
MAN8=		poppassd.8

post-install:
	@ strip ${PREFIX}/libexec/poppassd
	@ ${INSTALL_MAN} ${FILESDIR}/poppassd.8 ${PREFIX}/man/man8/

.include <bsd.port.mk>
