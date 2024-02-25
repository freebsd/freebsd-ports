PORTNAME=	dhcping
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Send DHCP request to DHCP server for monitoring purposes
WWW=		https://www.mavetju.org/unix/general.php

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/dhcping \
		share/man/man8/dhcping.8.gz

.include <bsd.port.mk>
