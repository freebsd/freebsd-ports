# New ports collection makefile for:   cisco_conf
# Date created:        27 March 2001
# Whom:                Anton Voronin <anton@urc.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	cisco_conf
PORTVERSION=	1.1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.chelcom.ru/~anton/projects/files/
DISTNAME=	ciscoconf-${PORTVERSION}
DIST_SUBDIR=	cisco_conf

MAINTAINER=	anton@chelcom.ru
COMMENT=	Simple configuration editor for Cisco devices

RUN_DEPENDS=	${LOCALBASE}/bin/joe:${PORTSDIR}/editors/joe

WRKSRC=		${WRKDIR}/ciscoconf

NO_BUILD=	YES

.include <bsd.port.mk>
