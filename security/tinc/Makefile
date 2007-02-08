# ex:ts=8
# Ports collection makefile for:	tinc
# Date created:			Jul 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tinc
PORTVERSION=	1.0.7
CATEGORIES=	security
MASTER_SITES=	http://www.tinc-vpn.org/packages/ \
		ftp://ftp.wiretapped.net/pub/security/network-security/tinc/ \
		http://www.mirrors.wiretapped.net/security/network-security/tinc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Virtual Private Network (VPN) daemon

LIB_DEPENDS=	lzo.1:${PORTSDIR}/archivers/lzo

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_GCC=	3.4+
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--localstatedir=/var --infodir=${PREFIX}/${INFO_PATH} \
		--mandir=${MANPREFIX}/man
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN5=	tinc.conf.5
MAN8=	tincd.8
INFO=	tinc

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} \
	    's/OpenSSL_add_all_algorithms/OpenSSL_add_all_ciphers/' \
	    ${WRKSRC}/configure

.include <bsd.port.mk>
