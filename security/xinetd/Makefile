# New ports collection makefile for:	xinetd
# Date created:				28 June 1996
# Whom:					markm
#
# $FreeBSD$
#

PORTNAME=	xnited
PORTVERSION= 	2.1.8.8p2
CATEGORIES=	security
MASTER_SITES=	http://synack.net/xinetd/

MAINTAINER=	vanilla@FreeBSD.org

FETCH_BEFORE_ARGS=	-b
GNU_CONFIGURE=	yes
ALL_TARGET=	build
CONFIGURE_ARGS=	--with-loadavg --with-libwrap

MAN5=		xinetd.conf.5
MAN8=		xinetd.8 xinetd.log.8

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/xinetd.sh ]; then \
		${ECHO} "Install ${PREFIX}/etc/rc.d/xinetd.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/xinetd.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/xinetd ] &&" >> ${PREFIX}/etc/rc.d/xinetd.sh; \
		${ECHO} "${PREFIX}/sbin/xinetd -pid 2> /var/run/xinetd.pid &&" >> ${PREFIX}/etc/rc.d/xinetd.sh; \
		${ECHO} "${ECHO} -n ' xinetd'" >> ${PREFIX}/etc/rc.d/xinetd.sh; \
		${CHMOD} 751 ${PREFIX}/etc/rc.d/xinetd.sh; \
	fi
	strip ${PREFIX}/sbin/xinetd

.include <bsd.port.mk>
