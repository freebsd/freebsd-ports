# New ports collection makefile for:	wnews
# Date created:				July 11, 2004
# Whom:					Samy Al Bahra <samy@kerneled.org>
#
# $FreeBSD$
#

PORTNAME=	wnews
PORTVERSION=	0.8
CATEGORIES=	www
MASTER_SITES=	http://samy.kerneled.org/stuff/

MAINTAINER=	samy@kerneled.org
COMMENT=	An RSS news client for the UNIX console

MAN1=		wnews.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/wnews

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes

OPTIONS=	GTK2 "build the GTK+ 2.0 interface" off

.include <bsd.port.pre.mk>

.if defined(WITH_GTK2)
CONFIGURE_ARGS+=--with-gtk2
USE_GNOME+=	gtk20
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\(GTKCFLAGS="\)|\1${PTHREAD_CFLAGS} |; \
		s|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/configure

.include <bsd.port.post.mk>
