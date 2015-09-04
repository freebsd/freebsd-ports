# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pfinger
PORTVERSION=	0.7.10
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://www.xelia.ch/unix/pfinger/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Highly configurable, secure, and portable finger daemon

CONFLICTS=	gnu-finger-1.*

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	X11
OPTIONS_SUB=	yes

X11_USE=	GNOME=gtk12
X11_CONFIGURE_OFF=	--without-client

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/src/configfile.c
	@${REINPLACE_CMD} -e 's|<utmp.h>|<utmpx.h>|' ${WRKSRC}/configure

.include <bsd.port.mk>
