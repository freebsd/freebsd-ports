# New ports collection makefile for:	cfs
# Date created:		30 Jul 1997
# Whom:			John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

PORTNAME=	cfs
PORTVERSION=	1.4.1
PORTREVESION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.crypto.com/software/

MAINTAINER=	green@FreeBSD.org
COMMENT=	A cryptographic file system implemented as a user-space NFS server

ALL_TARGET=	cfs
MAN1=		cattach.1 cdetach.1 cmkdir.1 cpasswd.1 cfssh.1
MAN8=		ccat.8 cfsd.8 cname.8

do-install:
	@cd ${WRKSRC}; \
	    ${INSTALL_PROGRAM} ccat cfsd cname ${PREFIX}/sbin; \
	    ${INSTALL_PROGRAM} cattach cdetach cmkdir cpasswd ${PREFIX}/bin; \
	    ${INSTALL_SCRIPT} cfssh ${PREFIX}/bin/cfssh; \
	    ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1; \
	    ${INSTALL_MAN} ${MAN8} ${PREFIX}/man/man8; \
	    ${MKDIR} ${PREFIX}/share/doc/cfs; \
	    ${INSTALL_DATA} README.install notes.ms ${PREFIX}/share/doc/cfs
	@if [ ! -f ${PREFIX}/etc/rc.d/cfsd.sh ]; then \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/cfsd.sh ${PREFIX}/etc/rc.d/cfsd.sh; \
	fi

.include <bsd.port.mk>
