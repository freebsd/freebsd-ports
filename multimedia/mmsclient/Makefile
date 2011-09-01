# New ports collection makefile for:	mmsclient
# Date created:				4 March 2002
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	mmsclient
PORTVERSION=	0.0.3
CATEGORIES=	multimedia audio net
MASTER_SITES=	http://ole.tange.dk/projekter/kontroversielt/www.geocities.com/majormms/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	mms_client-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to download Microsoft Media streams

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
MAN1=		mmsclient.1
PLIST_FILES=	bin/mmsclient

post-install:
	${INSTALL_MAN} ${FILESDIR}/mmsclient.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
