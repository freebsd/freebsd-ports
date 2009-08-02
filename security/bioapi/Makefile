# Ports collection makefile for:	bioapi
# Date created:				10 January 2006
# Whom:					Fredrik Lindberg <fli@shapeshifter.se>
#
# $FreeBSD$
#

PORTNAME=	bioapi
PORTVERSION=	1.2.2
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	http://www.qrivy.net/~michael/blua/bioapi/ \
		http://shapeshifter.se/pub/bioapi/

MAINTAINER=	fli@shapeshifter.se
COMMENT=	BioAPI library implementation

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
# Problems reported with higher optimization levels
CONFIGURE_ENV=CFLAGS="${CFLAGS} -O"
CONFIGURE_ARGS=	--localstatedir=/var/db/ --with-Qt-dir=no

USE_LDCONFIG=	yes

.include <bsd.port.mk>
