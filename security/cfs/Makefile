# New ports collection makefile for:	cfs
# Date created:		30 Jul 1997
# Whom:			John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

PORTNAME=	cfs
PORTVERSION= 	1.3.3.1
CATEGORIES=	security
MASTER_SITES=   ftp://ftp.hacktic.nl/pub/crypto/disk/ \
		ftp://ftp.uni-bielefeld.de/pub/crypto/replay/disk/
DISTNAME=	cfs-1.3.3bf

MAINTAINER=	green@FreeBSD.org

ALL_TARGET=	cfs
MAN1=		cattach.1 cdetach.1 cmkdir.1 cpasswd.1 cfssh.1
MAN8=		ccat.8 cfsd.8 cname.8
RESTRICTED=	"contains crypto code"

pre-build:
	@${CP} ${FILESDIR}/bf_tab.h ${WRKSRC}

do-install:
	@${CP} ${WRKSRC}/ssh.1 ${WRKSRC}/cfssh.1
	@cd ${WRKSRC}; \
	    ${INSTALL_PROGRAM} ccat cfsd cname ${PREFIX}/sbin; \
	    ${INSTALL_PROGRAM} cattach cdetach cmkdir cpasswd ${PREFIX}/bin; \
	    ${INSTALL_SCRIPT} ssh ${PREFIX}/bin/cfssh; \
	    ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1; \
	    ${INSTALL_MAN} ${MAN8} ${PREFIX}/man/man8; \
	    ${MKDIR} ${PREFIX}/share/doc/cfs; \
	    ${INSTALL_DATA} README.install notes.ms ${PREFIX}/share/doc/cfs; \
	    ${INSTALL_SCRIPT} cfsd.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
