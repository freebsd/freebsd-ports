# New ports collection makefile for:	libmxp
# Date created:		2007-02-25
# Whom:			Michael Nottebrock <lofi@kiste>
#
# $FreeBSD$
#

PORTNAME=	libmxp
PORTVERSION=	0.2.2
CATEGORIES=	net games textproc
MASTER_SITES=	http://www.kmuddy.com/libmxp/files/

MAINTAINER=	lofi@freebsd.org
COMMENT=	Parser for the MUD eXtension protocol

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's|objformat=.*|objformat=elf|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
