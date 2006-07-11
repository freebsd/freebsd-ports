# New ports collection makefile for:	libeXosip2
# Date created:				12 April 2006
# Whom:					Muhammad Moinur Rahman <bd_subzero@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	libeXosip2
PORTVERSION=	2.2.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	exosip

MAINTAINER=	bd_subzero@yahoo.com
COMMENT=	GPL library that extends the capability of the oSIP library

LIB_DEPENDS=	osip2:${PORTSDIR}/net/libosip2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-tools
INSTALLS_SHLIB=	yes

OPTIONS=	UCL "Use uclmmbase IP multicast library " off

.include <bsd.port.pre.mk>

.if defined(WITH_UCL)
LIB_DEPENDS+=		uclmmbase:${PORTSDIR}/devel/uclmmbase
CONFIGURE_ARGS+=	--enable-ucl
CONFIGURE_ENV+=		CFLAGS=-I${LOCALBASE}/include
PLIST_SUB+=		JOSUA=""
.else
CONFIGURE_ARGS+=	--disable-josua
PLIST_SUB+=		JOSUA="@comment "
.endif

.include <bsd.port.post.mk>
