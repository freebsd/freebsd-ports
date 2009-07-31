# New ports collection makefile for:	pidgin-manualsize
# Date created:		8 May 2008
# Whom:			Joseph S. Atkinson <jsatkinson@embarqmail.com>
#
# $FreeBSD$
#

PORTNAME=	manualsize
PORTVERSION=	0.6a
PORTREVISION?=	1
CATEGORIES=	net-im
MASTER_SITES=	http://myfotomx.com/files/ \
		http://wickedmachine.net/~jsa/FreeBSD/distfiles/
PKGNAMEPREFIX=	pidgin-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	jsa@wickedmachine.net
COMMENT=	Plugin to allow manual resizing of Pidgin's message input area

BUILD_DEPENDS=	${LOCALBASE}/include/pidgin/pidgin.h:${PORTSDIR}/net-im/pidgin
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin

MAKEFILE=	makefile

PLIST_FILES=	lib/pidgin/manualsize.so

USE_BZIP2=	yes
ALL_TARGET=	manualsize.so

post-patch:
	@${REINPLACE_CMD} -e 's|-g root -m 755|-g wheel -m 755|g' ${WRKSRC}/makefile

.include <bsd.port.mk>
