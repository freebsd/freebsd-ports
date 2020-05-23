# Created by: Talal Al Dik (tad@vif.com)
# $FreeBSD$

PORTNAME=	sngrep
PORTVERSION=	1.4.7
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	tad@vif.com
COMMENT=	SIP Packet display and capture

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf localbase ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	irontec

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	OPENSSL PCRE UNICODE IPV6 EEP
OPTIONS_DEFAULT=	IPV6 EEP UNICODE OPENSSL

OPENSSL_DESC=	Adds OpenSSL support to parse TLS captured messages
OPENSSL_CONFIGURE_ON=	--with-openssl
OPENSSL_USES=		ssl

PCRE_DESC=	Adds Perl Compatible regex support
PCRE_CONFIGURE_ON=	--with-pcre
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre

UNICODE_DESC=	Adds Ncurses UTF-8/Unicode support
UNICODE_CONFIGURE_ON=	--enable-unicode

IPV6_DESC=	Enable IPv6 packet capture support
IPV6_CONFIGURE_ON=	--enable-ipv6

EEP_DESC=	Enable EEP packet send/receive support
EEP_CONFIGURE_ON=	--enable-eep

.include <bsd.port.mk>
