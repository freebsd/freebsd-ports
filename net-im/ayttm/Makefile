# New ports collection makefile for:	everybuddy
# Date created:			1 Mar 2000
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	everybuddy
PORTVERSION=	0.4.2
CATEGORIES=	net
MASTER_SITES=	http://www.everybuddy.com/files/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/b/beta/}

MAINTAINER=	jim@FreeBSD.org

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes

LIB_DEPENDS=	intl.2:${PORTSDIR}/devel/gettext
MAN1=		everybuddy.1

# no idea why config.h isn't created, but an empty one seems to work OK
post-patch:
	touch ${WRKSRC}/config.h

.include <bsd.port.mk>
