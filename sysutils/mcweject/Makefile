# New ports collection Makefile for:	mcweject
# Date created:				11 Jan 2005
# Whom:					Jason Bacon <jbacon@mcw.edu>
#
# $FreeBSD$
#

PORTNAME=	mcweject
PORTVERSION=	0.9
CATEGORIES=	sysutils
MASTER_SITES=	http://www.neuro.mcw.edu/~bacon/Ports/distfiles/

MAINTAINER=	jbacon@mcw.edu
COMMENT=	Removable media eject

MAN1=		eject.1
MANCOMPRESSED=	yes
SUB_FILES=	pkg-message

CONFLICTS=	eject-[0-9]*
PKGMESSAGE=	${WRKDIR}/pkg-message

PLIST_FILES=	sbin/eject share/examples/mcweject/eject.allow
PLIST_DIRS=	share/examples/mcweject

FORBIDDEN=	contains exploitable buffer overflow (CVE-2007-1719)

do-install:
	${MKDIR} ${PREFIX}/share/examples/mcweject
	${INSTALL_DATA} ${WRKSRC}/eject.allow.sample \
		${PREFIX}/share/examples/mcweject/eject.allow
	${INSTALL_PROGRAM} ${WRKSRC}/eject ${PREFIX}/sbin
	${CHMOD} 4511 ${PREFIX}/sbin/eject
	${INSTALL_DATA} ${WRKSRC}/eject.1 ${PREFIX}/man/man1
	${GZIP_CMD} ${PREFIX}/man/man1/eject.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
