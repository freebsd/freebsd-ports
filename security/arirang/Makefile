# Ports collection makefile for:  arirang
# Date created:			  Jun 4 2001
# Whom:				  Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	arirang
PORTVERSION=	1.6
PORTEPOCH=	1
CATEGORIES=	security www
MASTER_SITES=	${MASTER_SITE_PACKETSTORM} \
		http://monkey.org/~pilot/arirang/
MASTER_SITE_SUBDIR=	UNIX/cgi-scanners

MAINTAINER=	ports@oven.org
COMMENT=	Powerful webserver security scanner

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arirang ${PREFIX}/sbin
	${MKDIR} ${PREFIX}/share/arirang
	${CHMOD} 755 ${PREFIX}/share/arirang
	${INSTALL_DATA} ${WRKSRC}/scanrule/*.uxe ${PREFIX}/share/arirang

.include <bsd.port.mk>
