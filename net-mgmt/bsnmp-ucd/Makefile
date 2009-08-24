# New ports collection makefile for:	bsnmp-ucd
# Date created:				15 December 2007
# Whom:					Mikolaj Golub <to.my.trociny@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bsnmp-ucd
PORTVERSION=	0.3.0
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	to.my.trociny@gmail.com
COMMENT=	A bsnmpd module that implements parts of UCD-SNMP-MIB

USE_MAKE=	yes
USE_AUTOTOOLS=	libtool:22:env

MAN8=		bsnmp-ucd.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 601000
IGNORE=	bsnmpd lack of realization on FreeBSD < 6.1
.endif

.include <bsd.port.post.mk>
