# New ports collection makefile for:   nakenchat
# Date created:        01 July 2003
# Whom:                Michael Kohn  (mike@mikekohn.net)
#
# $FreeBSD$
#

PORTNAME=	nakenchat
PORTVERSION=	2.12
CATEGORIES=	net
MASTER_SITES=	http://downloads.mikekohn.net/nakenchat/

MAINTAINER=	olevole@olevole.ru
COMMENT=	Small (under 50k) chat server with many features

HAS_CONFIGURE=	yes
USE_RC_SUBR=	nakenchat

OPTIONS_DEFINE=	KEEPALIVEOFF USERCHANLISTOFF DEBUG HIDDENCAVES DOTQ FUSERLIST ELITEFILTER

KEEPALIVEOFF_DESC=	Disable socket keepalive option
USERCHANLISTOFF_DESC=	Disable userlist based on channel
DEBUG_DESC=		Compile in debug code
HIDDENCAVES_DESC=	Enable hidden caves feature
DOTQ_DESC=		compile in .Q option
FUSERLIST_DESC=	support to save current userlist to a file
ELITEFILTER_DESC=	Enable the 3li73 filter

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWITH_KEEPALIVEOFF}
CONFIGURE_ARGS+=	--disable-keepalive
.endif

.if ${PORT_OPTIONS:MWITH_USERCHANLISTOFF}
CONFIGURE_ARGS+=	--disable-userchanlist
.endif

.if ${PORT_OPTIONS:MWITH_DEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MWITH_HIDDENCAVES}
CONFIGURE_ARGS+=	--enable-hidden-caves
.endif

.if ${PORT_OPTIONS:MWITH_DOTQ}
CONFIGURE_ARGS+=	--enable-dotQ
.endif

.if ${PORT_OPTIONS:MWITH_FUSERLIST}
CONFIGURE_ARGS+=	--enable-whofile
.endif

.if ${PORT_OPTIONS:MWITH_ELITEFILTER}
CONFIGURE_ARGS+=	--enable-elite
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/nakenchat.conf ]; then \
		${CP} -p ${PREFIX}/etc/nakenchat.conf.sample ${PREFIX}/etc/nakenchat.conf ; \
	fi

.include <bsd.port.mk>
