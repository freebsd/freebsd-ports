# New ports collection makefile for:	tinyfugue
# Date created:		4 January 1997
# Whom:			mike@binghamton.edu
#
# $FreeBSD$
#

PORTNAME=	tf
PORTVERSION=	5.0b6
CATEGORIES=	net games
MASTER_SITES=	http://ftp.tcp.com/pub/mud/Clients/tinyfugue/ \
		ftp://tf.tcp.com/pub/tinyfugue/
DISTVERSION=	${PORTVERSION:S/.//}
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	A popular programmable MUD client, with macro support and more

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-manpage --enable-version

PLIST_SUB=	DISTNAME=${DISTNAME}

MAN1=		tf.1

.include <bsd.port.mk>
