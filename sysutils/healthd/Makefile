# New ports collection makefile for:	healthd
# Date created:		15 November 1999
# Whom:			jim@thehousleys.net
#
# $FreeBSD$
#

PORTNAME=	healthd
PORTVERSION=	0.4.2
CATEGORIES=	sysutils
MASTER_SITES=	http://healthd.thehousleys.net/

MAINTAINER=	jim@thehousleys.net

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--exec-prefix=${PREFIX}

MAN8=		healthd.8

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/healthd.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/healthd.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/healthd.sh; \
		${ECHO} "[ -x ${PREFIX}/bin/healthd ] && ${PREFIX}/bin/healthd > /dev/null && ${ECHO} -n ' healthd'" >> ${PREFIX}/etc/rc.d/healthd.sh; \
		${CHMOD} 751 ${PREFIX}/etc/rc.d/healthd.sh; \
	fi
	@if [ ! -f ${PREFIX}/etc/healthd.conf ]; then \
		${ECHO} "Installing ${PREFIX}/etc/healthd.conf configuration file."; \
		${ECHO} "It is recommended you edit this file to match your system"; \
		${ECHO} "before running the program."; \
		${CP} ${PREFIX}/etc/healthd.conf.sample ${PREFIX}/etc/healthd.conf; \
	fi

.include <bsd.port.mk>
