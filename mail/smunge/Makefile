# New ports collection makefile for:   smunge
# Date created:		20 Jun 2000
# Whom:			Domas Mituzas <midom@dammit.lt>
#
# $FreeBSD$

PORTNAME=	smunge
PORTVERSION=	1.3.5
CATEGORIES=	mail
MASTER_SITES=	http://www.i2pi.com/smunge/

MAINTAINER=	midom@dammit.lt

LIB_DEPENDS=	ldap:${PORTSDIR}/net/openldap

USE_GMAKE=	true
WRKSRC=		${WRKDIR}
ALL_TARGET=	smunged

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/smunged ${PREFIX}/sbin/smunged

.include <bsd.port.mk>
