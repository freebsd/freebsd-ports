# New ports collection makefile for:	olsrd
# Date created:		6 April 2005
# Whom:			dave@dogwood.com
#
# $FreeBSD$
#

PORTNAME=	olsrd
PORTVERSION=	0.4.9
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.olsr.org/releases/0.4/

MAINTAINER=	dave@dogwood.com
COMMENT=	OLSR routing daemon

BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend

.if defined(WITH_MULTI_IF)
BUILD_DEPENDS+=	libnet-config:${PORTSDIR}/net/libnet-devel
.endif

USE_BISON=	yes
USE_GMAKE=	yes

USE_RC_SUBR=	olsrd.sh
MAN8=		olsrd.8
MAN5=		olsrd.conf.5
MANCOMPRESSED=	yes

.if defined(WITH_MULTI_IF)
MAKE_ARGS+=	OS=fbsd-ll
.else
MAKE_ARGS+=	OS=fbsd
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502000
IGNORE=		needs ieee80211.h headers
.endif

.if !defined(WITH_MULTI_IF)
pre-everything::
	@${ECHO_MSG}	""
	@${ECHO_MSG}	" To enable multiple interface support make with"
	@${ECHO_MSG}	" WITH_MULTI_IF defined"
	@${ECHO_MSG}	""
.endif

post-install:
	@${ECHO_MSG}	""
	@${ECHO_MSG}	" Set olsrd_enable=\"YES\" in /etc/rc.conf to enable"
	@${ECHO_MSG}	""

.include <bsd.port.post.mk>
