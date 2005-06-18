# New ports collection makefile for:	asterisk-oh323
# Date created:		17 Jun 2005
# Whom:			Andriy Pylypenko <bamby@portaone.com>
#
# $FreeBSD$
#

PORTNAME=	asterisk-oh323
PORTVERSION=	0.6.5
CATEGORIES=	net
MASTER_SITES=	http://www.inaccessnetworks.com/asterisk-oh323/download/

MAINTAINER=	bamby@portaone.com
COMMENT=	A H.323 support module for the Asterisk soft PBX

BUILD_DEPENDS= 	${NONEXISTENT}:${PORTSDIR}/devel/pwlib:build \
	    	${NONEXISTENT}:${PORTSDIR}/net/openh323:build \
	    	${LOCALBASE}/sbin/asterisk:${PORTSDIR}/net/asterisk

USE_GMAKE=	yes

PLIST_FILES=	lib/liboh323wrapd.a
PLIST_FILES+=	lib/asterisk/modules/chan_oh323.so
PLIST_FILES+=	etc/asterisk/oh323.conf.sample

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
