# ex:ts=8
# New ports collection makefile for:	nylon
# Date created:			Jun 11, 2001
# Whom:				William Ward <William.Ward@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	nylon
PORTVERSION=	1.1
CATEGORIES=	net
MASTER_SITES=	http://monkey.org/~marius/nylon/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent

GNU_CONFIGURE=	yes
# Necessary for $PREFIX to work:
CONFIGURE_ARGS=	--with-libevent=${LOCALBASE}

MAN1=		nylon.1

post-install:
	${INSTALL_DATA} ${FILESDIR}/nylon.conf ${PREFIX}/etc

.include <bsd.port.mk>
