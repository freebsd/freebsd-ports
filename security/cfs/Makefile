# New ports collection makefile for:	cfs
# Version required:	1.3.3
# Date created:		30 Jul 1997
# Whom:			John Polstra <jdp@polstra.com>
#
# $Id$
#

DISTNAME=	cfs-1.3.3
CATEGORIES=	security
MASTER_SITES=	ftp://utopia.hacktic.nl/pub/crypto/disk/ \
		ftp://ftp.informatik.uni-hamburg.de/pub/virus/crypt/disk/

MAINTAINER=	jdp@polstra.com

ALL_TARGET=	cfs
MAN1=		cattach.1 cdetach.1 cmkdir.1 cpasswd.1
MAN8=		ccat.8 cfsd.8 cname.8
RESTRICTED=	"contains crypto code"

do-install:
	@cd ${WRKSRC}; \
	    ${INSTALL_PROGRAM} ccat cfsd cname ${PREFIX}/sbin; \
	    ${INSTALL_PROGRAM} cattach cdetach cmkdir cpasswd ${PREFIX}/bin; \
	    ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1; \
	    ${INSTALL_MAN} ${MAN8} ${PREFIX}/man/man8; \
	    ${MKDIR} ${PREFIX}/share/doc/cfs; \
	    ${INSTALL_DATA} README.install notes.ms ${PREFIX}/share/doc/cfs; \
	    ${INSTALL_SCRIPT} cfsd.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
