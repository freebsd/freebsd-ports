# New ports collection makefile for:	opensc
# Date created:		10 September 2002
# Whom:			Bruce M Simpson <bms@spc.org>
#
# $FreeBSD$
#

PORTNAME=	opensc
PORTVERSION=	0.7.0
CATEGORIES=	security devel
MASTER_SITES=	http://www.opensc.org/files/

MAINTAINER=	bms@spc.org

LIB_DEPENDS=	pcsclite.0:${PORTSDIR}/devel/pcsc-lite	\
		ldap.2:${PORTSDIR}/net/openldap2

INSTALLS_SHLIB= yes
USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pcsclite=${LOCALBASE}	\
		--with-ldap-lib=openldap	\
		--with-ldap-dir=${LOCALBASE}

MAN1=		pkcs15-crypt.1 pkcs15-init.1
MAN5=		pkcs15-profile.5
MAN7=		pkcs15.7

.include <bsd.port.mk>
