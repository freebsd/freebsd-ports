# New ports collection makefile for:   cpu
# Date created:        15 November 2003
# Whom:                Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cpu
PORTVERSION=	1.4.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cpu

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Change Password Utility for LDAP

GNU_CONFIGURE=	yes
USE_OPENLDAP=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/cpu --with-ldap=${LOCALBASE}

MAN5=		cpu.conf.5
MAN8=		cpu.8 cpu-ldap.8

.include <bsd.port.mk>
