# New ports collection makefile for:	xinetd
# Version required:	2.2.1
# Date created:		28 June 1996
# Whom:			markm
#
# $Id: Makefile,v 1.4 1997/12/04 03:40:06 vanilla Exp $
#

DISTNAME=	xinetd-2.2.1
CATEGORIES=	security
MASTER_SITES=	ftp://coast.cs.purdue.edu/pub/tools/unix/xinetd/

MAINTAINER=	markm@FreeBSD.ORG

MAN1=		xinetd.1
MAN5=		xinetd.conf.5 xinetd.log.5

do-build:
	cd ${WRKSRC} ; ./compile-src -os freebsd2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xinetd/xinetd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/xinetd/xinetd.man ${PREFIX}/man/man1/xinetd.1
	${INSTALL_MAN} ${WRKSRC}/xinetd/xinetd.conf.man ${PREFIX}/man/man5/xinetd.conf.5
	${INSTALL_MAN} ${WRKSRC}/xinetd/xinetd.log.man ${PREFIX}/man/man5/xinetd.log.5

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/xinetd.sh ]; then \
		${ECHO} "Install ${PREFIX}/etc/rc.d/xinetd.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/xinetd.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/xinetd ] && ${PREFIX}/sbin/xinetd && echo -n' xinetd'" >> ${PREFIX}/etc/rc.d/xinetd.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/xinetd.sh; \
	fi

.include <bsd.port.mk>
