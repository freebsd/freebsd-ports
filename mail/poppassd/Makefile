# Created by: Andrew Stevenson <andrew@ugh.net.au> based heavily on the changes by Stephen Melvin <melvin@zytek.com>
# $FreeBSD$

PORTNAME=	poppassd
PORTVERSION=	4.0
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.qualcomm.com/eudora/servers/unix/password/
DISTNAME=	pwserve-4
EXTRACT_SUFX=

MAINTAINER=	tedm@ipinc.net
COMMENT=	Server to allow users to change their password from within Eudora

BROKEN=		unfetchable

EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| ${SED} -e '1,16d' | ${SH}
WRKSRC=			${WRKDIR}/poppassd
ALL_TARGET=	poppassd
PLIST_FILES=	libexec/poppassd man/man8/poppassd.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/poppassd ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${FILESDIR}/poppassd.8 ${STAGEDIR}${MANPREFIX}/man/man8/

.include <bsd.port.mk>
