# New ports collection makefile for:	adtool
# Date created:							Wed 23 Apr 2003
# Whom:									joseph@randomnetworks.com
#
# $FreeBSD$
#

PORTNAME=			adtool
PORTVERSION=		1.1
CATEGORIES=			sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	Active Directory administration tool

LIB_DEPENDS+= ldap.2:${PORTSDIR}/net/openldap21
LIB_DEPENDS+= lber.2:${PORTSDIR}/net/openldap21

USE_GMAKE=		yes
HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} --with-ldap=${LOCALBASE}

MAN1=		adtool.1

.include <bsd.port.mk>
