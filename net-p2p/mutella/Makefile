# New ports collection makefile for:	mutella
# Date created:				2/12/2001
# Whom:			Dominic Marks <d.marks@student.umist.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	mutella
PORTVERSION=	0.4.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	d.marks@student.umist.ac.uk

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
	${REINPLACE_CMD} -e 's|ulong|u_long|' \
		${WRKSRC}/mutella/asyncsocket.cpp \
		${WRKSRC}/mutella/asyncsocket.h

.include <bsd.port.mk>
