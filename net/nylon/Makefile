# ex:ts=8
# New ports collection makefile for:	nylon
# Date created:			Jun 11, 2001
# Whom:				William Ward <William.Ward@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	nylon
PORTVERSION=	1.21
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://monkey.org/~marius/nylon/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Unix SOCKS 4 and 5 proxy server

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

USE_RC_SUBR=	nylon.sh

GNU_CONFIGURE=	yes
# Necessary for $PREFIX to work:
CONFIGURE_ARGS=	--with-libevent=${LOCALBASE}

MAN1=		nylon.1

PLIST_FILES=	bin/nylon etc/nylon.conf.sample

post-install:
	${INSTALL_DATA} ${FILESDIR}/nylon.conf ${PREFIX}/etc/nylon.conf.sample

.include <bsd.port.mk>
