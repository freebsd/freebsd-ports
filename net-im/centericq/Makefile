# ex:ts=8
# New ports collection makefile for:   	centericq
# Date created:                        	25 December 1999
# Whom:                                 Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	centericq
PORTVERSION=	4.7.1
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	http://konst.org.ua/download/

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	intl.2:${PORTSDIR}/devel/gettext \
		iconv.3:${PORTSDIR}/converters/libiconv \
		sigc.1:${PORTSDIR}/devel/libsigc++

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=	centericq.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

.include <bsd.port.post.mk>
