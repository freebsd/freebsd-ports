# New ports collection makefile for:	tinyfugue
# Date created:		4 January 1997
# Whom:			mike@binghamton.edu
#
# $FreeBSD$
#

PORTNAME=	tf
PORTVERSION=	5.0a14
CATEGORIES=	net games
MASTER_SITES=	http://ftp.tcp.com/pub/mud/Clients/tinyfugue/ \
		ftp://ftp.minet.uni-jena.de/pub/tf/
DISTNAME=	tf-50a14

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	A popular programmable MUD client, with macro support and more

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-manpage --enable-version

PLIST_SUB=	DISTNAME=${DISTNAME}

MAN1=		tf.1

.include <bsd.port.mk>
