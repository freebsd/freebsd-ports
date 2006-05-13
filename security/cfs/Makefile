# New ports collection makefile for:	cfs
# Date created:		30 Jul 1997
# Whom:			John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

PORTNAME=	cfs
PORTVERSION=	1.4.1
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://www.crypto.com/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A cryptographic file system implemented as a user-space NFS server

ALL_TARGET=	cfs
MAN1=		cattach.1 cdetach.1 cmkdir.1 cpasswd.1 cfssh.1
MAN8=		ccat.8 cfsd.8 cname.8

CFSD_BOOTSTRAP=	${PREFIX}/cfsd-bootstrap
USE_RC_SUBR=	cfsd.sh
SUB_FILES=	pkg-message
SUB_LIST=	CFSD_BOOTSTRAP=${CFSD_BOOTSTRAP}
PLIST_SUB=	CFSD_BOOTSTRAP=${CFSD_BOOTSTRAP}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700000
BROKEN=		"Does not compile on FreeBSD >= 7.0"
.endif

post-patch:
	${REINPLACE_CMD} 's/^\.TH SSH/.TH CFSSH/' ${WRKSRC}/cfssh.1

do-install:
	@cd ${WRKSRC}; \
	    ${INSTALL_PROGRAM} ccat cfsd cname ${PREFIX}/sbin; \
	    ${INSTALL_PROGRAM} cattach cdetach cmkdir cpasswd ${PREFIX}/bin; \
	    ${INSTALL_SCRIPT} cfssh ${PREFIX}/bin/cfssh; \
	    ${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1; \
	    ${INSTALL_MAN} ${MAN8} ${PREFIX}/man/man8; \
	    ${MKDIR} ${PREFIX}/share/doc/cfs; \
	    ${INSTALL_DATA} README.install notes.ms ${PREFIX}/share/doc/cfs
	${INSTALL} -d ${_BINOWNGRP} -m 0 ${CFSD_BOOTSTRAP}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
