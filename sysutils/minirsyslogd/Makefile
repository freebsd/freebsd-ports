# New ports collection makefile for:	minirsyslogd
# Date created:		2003-10-30
# Whom:			lx@redundancy.redundancy.org
#
# $FreeBSD$
#

PORTNAME=	minirsyslogd
PORTVERSION=	1.02
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.clueby4.org/minirsyslogd/

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	Minimal, fast and secure syslog receiver

MAN8=		minirsyslogd.8
MANCOMPRESSED=	yes

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8.gz ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
