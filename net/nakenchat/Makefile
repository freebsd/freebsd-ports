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

MAINTAINER=	oleg.ginzburg@nevosoft.ru
COMMENT=	Small (under 50k) chat server with many features

HAS_CONFIGURE=	yes
USE_RC_SUBR=	nakenchat

OPTIONS=	KEEPALIVEOFF "Disable socket keepalive option" off \
		USERCHANLISTOFF "Disable userlist based on channel" off  \
		DEBUG "Compile in debug code" off \
		HIDDENCAVES "Enable hidden caves feature" off \
		DOTQ "compile in .Q option" off \
		FUSERLIST "support to save current userlist to a file" off \
		ELITEFILTER "Enable the 3li73 filter" off

.include <bsd.port.pre.mk>

.if defined(WITH_KEEPALIVEOFF)
CONFIGURE_ARGS+=	--disable-keepalive
.endif

.if defined(WITH_USERCHANLISTOFF)
CONFIGURE_ARGS+=	--disable-userchanlist
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_HIDDENCAVES)
CONFIGURE_ARGS+=	--enable-hidden-caves
.endif

.if defined(WITH_DOTQ)
CONFIGURE_ARGS+=	--enable-dotQ
.endif

.if defined(WITH_FUSERLIST)
CONFIGURE_ARGS+=	--enable-whofile
.endif

.if defined(WITH_ELITEFILTER)
CONFIGURE_ARGS+=	--enable-elite
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/nakenchat.conf ]; then \
		${CP} -p ${PREFIX}/etc/nakenchat.conf.sample ${PREFIX}/etc/nakenchat.conf ; \
	fi

.include <bsd.port.post.mk>
