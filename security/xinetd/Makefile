# New ports collection makefile for:	xinetd
# Version required:			2.1.8.6b5
# Date created:				28 June 1996
# Whom:					markm
#
# $Id: Makefile,v 1.6 1998/12/06 09:34:31 vanilla Exp $
#

DISTNAME=	xinetd-2.1.8.6b5
CATEGORIES=	security
MASTER_SITES=	http://synack.net/xinetd/

MAINTAINER=	markm@FreeBSD.ORG

FETCH_BEFORE_ARGS=	-b
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	build

MAN5=		xinetd.conf.5
MAN8=		xinetd.8 xinetd.log.8

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/xinetd.sh ]; then \
		${ECHO} "Install ${PREFIX}/etc/rc.d/xinetd.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/xinetd.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/xinetd ] && ${PREFIX}/sbin/xinetd && echo -n ' xinetd'" >> ${PREFIX}/etc/rc.d/xinetd.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/xinetd.sh; \
	fi
	strip ${PREFIX}/sbin/xinetd

.include <bsd.port.mk>
