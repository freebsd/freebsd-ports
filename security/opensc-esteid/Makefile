# New ports collection makefile for:	opensc-esteid
# Date created:				8 September 2003
# Whom:					Sven Petai <hadara@bsd.ee>
#
# $FreeBSD$
#

PORTNAME=	esteid
PORTVERSION=	0.7.0.1
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	http://marie.vtl.ee/esteid/
PKGNAMEPREFIX=	opensc-
DISTNAME=	opensc-esteid-0.7.0-1

MAINTAINER=	hadara@bsd.ee
COMMENT=	ISO 7816 Smartcard API Library (OpenSSH Compatible)

LIB_DEPENDS=	pcsclite.0:${PORTSDIR}/devel/pcsc-lite

USE_OPENLDAP_VER=	20
INSTALLS_SHLIB=	yes
USE_OPENSSL=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pcsclite=${LOCALBASE}    \
		--with-ldap-lib=openldap        \
		--with-ldap-dir=${LOCALBASE}    \
		--with-plugin-dir=${LOCALBASE}/share/opensc/plugins

MAN1=		pkcs15-crypt.1 pkcs15-init.1 pkcs15-tool.1 \
		cryptoflex-tool.1 \
		opensc-config.1 opensc-explorer.1 opensc-tool.1
MAN5=		pkcs15-profile.5
MAN7=		pkcs15.7 opensc.7

.include <bsd.port.mk>
