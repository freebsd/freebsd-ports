# Created by: Fredrik Lindberg <fli@shapeshifter.se>
# $FreeBSD$

PORTNAME=	bioapi
PORTVERSION=	1.2.2
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	http://www.qrivy.net/~michael/blua/bioapi/ \
		http://shapeshifter.se/pub/bioapi/

MAINTAINER=	fli@shapeshifter.se
COMMENT=	BioAPI library implementation

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
# Problems reported with higher optimization levels
CFLAGS+=	-O
CONFIGURE_ARGS=	--localstatedir=/var/db/ --with-Qt-dir=no

USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
