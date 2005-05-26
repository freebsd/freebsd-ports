# New ports collection makefile for:	adtool
# Date created:				Wed 23 Apr 2003
# Whom:					joseph@randomnetworks.com
#
# $FreeBSD$
#

PORTNAME=	adtool
PORTVERSION=	1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://dexy.mine.nu/adtool/

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	Active Directory administration tool

USE_GMAKE=	yes
USE_OPENLDAP=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		--with-ldap=${LOCALBASE}

MAN1=		adtool.1

.include <bsd.port.mk>
