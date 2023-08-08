PORTNAME=	fragrouter
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://monkey.org/~dugsong/ \
		LOCAL/fuz \
		LOCAL/ohauer

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Tool for testing network IDS implementations

GNU_CONFIGURE=	yes
CFLAGS+=	-Wno-pointer-sign

PLIST_FILES=	sbin/fragrouter \
		man/man8/fragrouter.8.gz

.include <bsd.port.mk>
