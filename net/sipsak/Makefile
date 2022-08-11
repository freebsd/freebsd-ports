PORTNAME=	sipsak
PORTVERSION=	0.9.6
CATEGORIES=	net
MASTER_SITES=	BERLIOS
DISTFILES=	sipsak-0.9.6-1.tar.gz

MAINTAINER=	jesusr@FreeBSD.org
COMMENT=	Small command line tool for SIP testing

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: address
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: address

USE_CSTD=	gnu89
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/sipsak \
		man/man1/sipsak.1.gz

.include <bsd.port.mk>
