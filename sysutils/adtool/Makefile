# New ports collection makefile for:	adtool
# Date created:				Wed 23 Apr 2003
# Whom:					joseph@randomnetworks.com
#
# $FreeBSD$
#

PORTNAME=	adtool
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://gp2x.org/adtool/

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	Active Directory administration tool

USE_GMAKE=	yes
USE_OPENLDAP=	yes
USE_AUTOTOOLS=	libtool

CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}

MAN1=		adtool.1

.include <bsd.port.mk>
