# New ports collection makefile for:	xinetd
# Version required:	2.2.1
# Date created:		28 June 1996
# Whom:			markm
#
# $Id: Makefile,v 1.3 1996/11/18 14:13:43 asami Exp $
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
	cd ${WRKSRC}/xinetd ; make install
	cd ${WRKSRC}/xinetd ; make install.man

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/xinetd.sh ]; then \
		${ECHO} "Install ${PREFIX}/etc/rc.d/xinetd.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/xinetd.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/xinetd ] && ${PREFIX}/sbin/xinetd && echo -n' xinetd'" >> ${PREFIX}/etc/rc.d/xinetd.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/xinetd.sh; \
	fi
.include <bsd.port.mk>
