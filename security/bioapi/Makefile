# Created by: Fredrik Lindberg <fli@shapeshifter.se>
# $FreeBSD$

PORTNAME=	bioapi
PORTVERSION=	1.2.2
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	http://www.qrivy.net/~michael/blua/bioapi/ \
		http://shapeshifter.se/pub/bioapi/

MAINTAINER= ports@FreeBSD.org
COMMENT=	BioAPI library implementation

USE_AUTOTOOLS=	libtool
USES=	tar:bzip2
GNU_CONFIGURE=	yes
# Problems reported with higher optimization levels
CFLAGS+=	-O
CONFIGURE_ARGS=	--localstatedir=/var/db/ --with-Qt-dir=no

USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
