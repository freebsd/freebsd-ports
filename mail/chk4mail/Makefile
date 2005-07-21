# New ports collection makefile for:	chk4mail
# Date created:				18 October 2002
# Whom:					johans
#
# $FreeBSD$
#

PORTNAME=	chk4mail
PORTVERSION=	2.19
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/johans/chk4mail/ \
		ftp://mud.stack.nl/pub/chk4mail/

MAINTAINER=	johans@stack.nl
COMMENT=	A utility to quickly check multiple folders for new email

PLIST_FILES=	bin/chk4mail bin/chkimap

MAN1=		chk4mail.1 chkimap.1

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
