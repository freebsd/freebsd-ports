# New ports collection makefile for:    upsd
# Version required:     2.0.1.6
# Date created:         11 Jul 1996
# Whom:                 alexis
#
# $FreeBSD$
#

DISTNAME=	upsd-2.0.1.6
PKGNAME=	upsd-2.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://www.ww.net/pub/wildwind/upsd/ \
		http://www.cre8tivegroup.com/ \
		ftp://ftp.sw.ru/pub/unix/upsd/

MAINTAINER=	alexis@ww.net

WRKSRC=		${WRKDIR}/upsd-2.0

pre-build:
	@${MV} ${WRKSRC}/config.h ${WRKSRC}/conf.h.orig
	@${SED} -e "s!@prefix@!${PREFIX}!g" ${WRKSRC}/conf.h.orig > ${WRKSRC}/conf.h

post-install:
	if [ ! -f ${PREFIX}/etc/upsd.conf ] ; then \
		${INSTALL} -c -o ${BINOWN} -g ${BINGRP} -m 644 \
			${FILESDIR}/upsd.conf ${PREFIX}/etc/upsd.conf; \
	fi

.include <bsd.port.mk>
