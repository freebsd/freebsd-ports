# Created by: Talal Al Dik (tad@vif.com)
# $FreeBSD$

PORTNAME=	sngrep
PORTVERSION=	1.4.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	tad@vif.com
COMMENT=	SIP Packet display and capture

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	irontec

GNU_CONFIGURE=	yes
USES=		autoreconf localbase ncurses

OPTIONS_DEFINE=	OPENSSL PCRE UNICODE IPV6 EEP

OPENSSL_DESC=	Adds OpenSSL support to parse TLS captured messages
OPENSSL_CONFIGURE_ON=	--with-openssl
OPENSSL_USES=		ssl

PCRE_DESC=	Adds Perl Compatible regex support
PCRE_CONFIGURE_ON=	--with-pcre
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre

UNICODE_DESC=	Adds Ncurses UTF-8/Unicode support
UNICODE_CONFIGURE_ON=	--enable-unicode
UNICODE_LIB_DEPENDS=	libncursesw.so:devel/ncurses

IPV6_DESC=	Enable IPv6 packet capture support
IPV6_CONFIGURE_ON=	--enable-ipv6

EEP_DESC=	Enable EEP packet send/receive support
EEP_CONFIGURE_ON=	--enable-eep

post-patch:
	@${REINPLACE_CMD} -e 's|ncursesw/ncurses.h|ncurses.h|g' \
		${WRKSRC}/configure.ac \
		${WRKSRC}/src/curses/scrollbar.h \
		${WRKSRC}/src/curses/ui_panel.h

.include <bsd.port.mk>
