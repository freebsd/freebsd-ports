# ex:ts=8
# New ports collection makefile for:	pfinger
# Date created:			Apr 25, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pfinger
PORTVERSION=	0.7.10
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.xelia.ch/unix/pfinger/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Highly configurable, secure and portable finger daemon

CONFLICTS=	gnu-finger-1.*

GNU_CONFIGURE=	yes
.if !defined(WITHOUT_X11)
USE_GNOME=	gtk12
PLIST_SUB+=	WITHOUT_X11=""
.else
CONFIGURE_ARGS+=--without-client
PLIST_SUB+=	WITHOUT_X11="@comment "
.endif

MAN1=	finger.1 pfinger.1
MAN5=	fingerconf.5
MAN8=	in.fingerd.8

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/src/configfile.c

.include <bsd.port.mk>
