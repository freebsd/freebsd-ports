# New ports collection makefile for:	bsnmp-ucd
# Date created:				15 December 2007
# Whom:					Mikolaj Golub <to.my.trociny@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bsnmp-ucd
PORTVERSION=	0.3.3
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	trociny@FreeBSD.org
COMMENT=	A bsnmpd module that implements parts of UCD-SNMP-MIB

USE_AUTOTOOLS=	libtool:env

MAN8=		bsnmp-ucd.8

post-patch:
	@${REINPLACE_CMD} -e '32,32 s/^.*/#include <sys\/queue.h>/' ${WRKSRC}/snmp_ucd.h

.include <bsd.port.mk>
