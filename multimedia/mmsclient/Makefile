# New ports collection makefile for:	mmsclient
# Date created:				4 March 2002
# Whom:					danfe@regency.nsu.ru
#
# $FreeBSD$
#

PORTNAME=	mmsclient
PORTVERSION=	0.0.3
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www.geocities.com/majormms/ \
		ftp://danfe.rimusa.org/tmp/ \
		http://inet.ssc.nsu.ru/~danfe/
DISTNAME=	mms_client-${PORTVERSION}

MAINTAINER=	danfe@regency.nsu.ru
COMMENT=	Download Microsoft Media streams

GNU_CONFIGURE=	yes
MAN1=		mmsclient.1
PLIST_FILES=	bin/mmsclient

post-install:
	@${INSTALL_MAN} ${FILESDIR}/mmsclient.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
