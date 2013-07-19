# Created by: Michael Kohn <mike@mikekohn.net>
# $FreeBSD$

PORTNAME=	nakenchat
PORTVERSION=	2.12
CATEGORIES=	net
MASTER_SITES=	http://downloads.mikekohn.net/nakenchat/

MAINTAINER=	olevole@olevole.ru
COMMENT=	Small (under 50k) chat server with many features

HAS_CONFIGURE=	yes
USE_RC_SUBR=	nakenchat

OPTIONS_DEFINE=	NOKEEPALIVE NOUSERCHANLIST DEBUG HIDDENCAVES DOTQ \
		FUSERLIST ELITEFILTER

NOKEEPALIVE_DESC=	Disable socket keepalive option
NOUSERCHANLIST_DESC=	Disable userlist based on channel
DEBUG_DESC=		Compile in debug code
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

.include <bsd.port.options.mk>

post-install:
	@if [ ! -f ${PREFIX}/etc/nakenchat.conf ]; then \
		${CP} -p ${PREFIX}/etc/nakenchat.conf.sample ${PREFIX}/etc/nakenchat.conf ; \
	fi

.include <bsd.port.mk>
