# New ports collection makefile for:	kdiff3
# Date created:		2003/01/03
# Whom:			Heiner Eichmann <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	kdiff3
PORTVERSION=	0.9.89
CATEGORIES=	textproc kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	A KDE3 graphical frontend for diff

USE_KDEBASE_VER=3
USE_AUTOTOOLS=	libtool:15

CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"

MAN1=	kdiff3.1

pre-configure:
.for i in config.h.in Makefile.in
	${TOUCH} ${WRKSRC}/${i}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 ||g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
