# New ports collection makefile for:   smunge
# Date created:		20 Jun 2000
# Whom:			Domas Mituzas <midom@dammit.lt>
#
# $FreeBSD$

PORTNAME=	smunge
PORTVERSION=	1.3.5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.i2pi.com/smunge/

MAINTAINER=	midom@dammit.lt
COMMENT=	Funneling POP3 proxy server

BROKEN=		Depends on net/openldap12 which is no more.

LIB_DEPENDS=	ldap:${PORTSDIR}/net/openldap12

USE_GMAKE=	true
WRKSRC=		${WRKDIR}
ALL_TARGET=	smunged
PLIST_FILES=	sbin/smunged

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/smunged ${PREFIX}/sbin/smunged

.include <bsd.port.mk>
