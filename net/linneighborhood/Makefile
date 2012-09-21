# New ports collection makefile for:    LinNeighborhood
# Date created:                         2003/04/06
# Whom:                                 Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	LinNeighborhood
PORTVERSION=	0.6.5
PORTREVISION=	12
CATEGORIES=	net
MASTER_SITES=	http://www.bnro.de/~schmidjo/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ gui for browsing and mounting SMB filesystems

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-10-20

RUN_DEPENDS=	smbclient:${PORTSDIR}/${SAMBA_PORT}

SAMBA_PORT?=	net/samba34

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include"
#                             ^
# this was done intentionaly in order to make `configure' pick up libintl.h
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CFLAGS+=	${PTHREAD_CFLAGS}

.include <bsd.port.pre.mk>

post-patch:
	${CP} ${FILESDIR}/mntent* ${WRKSRC}/src
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
