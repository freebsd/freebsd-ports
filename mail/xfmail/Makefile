# New ports collection makefile for:	xfmail
# Version required:     1.3.1
# Date created:		30 June 1996
# Whom:			gena
#
# $FreeBSD$
#

DISTNAME=       xfmail-1.4.0
CATEGORIES=     mail
MASTER_SITES=	ftp://xfmail.ufies.org/pub/xfmail/release/1.4.0/

MAINTAINER=	gena@NetVision.net.il

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		xforms.0:${PORTSDIR}/x11-toolkits/xforms

USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dead-keys --with-xkb-dead-keys
MAN1=		xfmail.1

.include <bsd.port.mk>
