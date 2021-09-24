# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>

PORTNAME=	mmsclient
PORTVERSION=	0.0.3
CATEGORIES=	multimedia audio net
MASTER_SITES=	http://ole.tange.dk/projekter/kontroversielt/www.geocities.com/majormms/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	mms_client-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to download Microsoft Media streams

LICENSE=	GPLv2

DEPRECATED=	Abandoned upstream, Microsoft deprecated MMS in 2003
EXPIRATION_DATE=2021-12-31

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/mmsclient man/man1/mmsclient.1.gz

post-install:
	${INSTALL_MAN} ${FILESDIR}/mmsclient.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
