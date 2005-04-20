# New ports collection makefile for:	opensc-esteid
# Date created:				8 September 2003
# Whom:					Sven Petai <hadara@bsd.ee>
#
# $FreeBSD$
#

PORTNAME=	esteid
PORTVERSION=	0.7.0.1
PORTREVISION=	2
CATEGORIES=	security devel
MASTER_SITES=	http://marie.vtl.ee/esteid/
PKGNAMEPREFIX=	opensc-
DISTNAME=	opensc-esteid-0.7.0-1

MAINTAINER=	hadara@bsd.ee
COMMENT=	ISO 7816 Smartcard API Library (OpenSSH Compatible)

LIB_DEPENDS=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite

USE_OPENLDAP=	yes
INSTALLS_SHLIB=	yes
USE_OPENSSL=	yes
USE_INC_LIBTOOL_VER=13
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pcsclite=${LOCALBASE}    \
		--with-ldap-lib=openldap        \
		--with-ldap-dir=${LOCALBASE}    \
		--with-plugin-dir=${LOCALBASE}/share/opensc/plugins
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include/PCSC"
USE_REINPLACE=	yes

MAN1=		pkcs15-crypt.1 pkcs15-init.1 pkcs15-tool.1 \
		cryptoflex-tool.1 \
		opensc-config.1 opensc-explorer.1 opensc-tool.1
MAN5=		pkcs15-profile.5
MAN7=		pkcs15.7 opensc.7

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Does not compile on amd64 (missing -fPIC)"
.endif

post-patch:
	${REINPLACE_CMD} -e "s,LPCSTR,LPCTSTR," ${WRKSRC}/src/libopensc/reader-pcsc.c
.include <bsd.port.post.mk>
