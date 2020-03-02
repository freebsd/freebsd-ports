# Created by: Michael Kohn <mike@mikekohn.net>
# $FreeBSD$

PORTNAME=	nakenchat
DISTVERSION=	3.00b1
CATEGORIES=	net
MASTER_SITES=	http://downloads.mikekohn.net/nakenchat/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Small (under 50k) chat server with many features

LICENSE=	GPLv2

HAS_CONFIGURE=	yes
USE_RC_SUBR=	nakenchat

OPTIONS_DEFINE=	NOKEEPALIVE NOUSERCHANLIST DEBUG HIDDENCAVES DOTQ \
		FUSERLIST ELITEFILTER

NOKEEPALIVE_DESC=	Disable socket keepalive option
NOUSERCHANLIST_DESC=	Disable userlist based on channel
HIDDENCAVES_DESC=	Enable hidden caves feature
DOTQ_DESC=		Compile in .Q option
FUSERLIST_DESC=		Support saving current userlist to a file
ELITEFILTER_DESC=	Enable the 3li73 filter

NOKEEPALIVE_CONFIGURE_ON=	--disable-keepalive
NOUSERCHANLIST_CONFIGURE_ON=	--disable-userchanlist
DEBUG_CONFIGURE_ON=		--enable-debug
HIDDENCAVES_CONFIGURE_ON=	--enable-hidden-caves
DOTQ_CONFIGURE_ON=		--enable-dotQ
FUSERLIST_CONFIGURE_ON=		--enable-whofile
ELITEFILTER_CONFIGURE_ON=	--enable-elite

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nakenchat \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/nakenchat.conf \
		${STAGEDIR}${PREFIX}/etc/nakenchat.conf.sample

.include <bsd.port.mk>
