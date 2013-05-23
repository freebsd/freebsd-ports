# Created by: mharo@area51.fremont.ca.us
# $FreeBSD$

PORTNAME=	naim
PORTVERSION=	0.11.8.3.2
CATEGORIES=	net-im irc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	j@scre.ws
COMMENT=	Console ncurses-based AIM, ICQ, IRC, and Lily client

GNU_CONFIGURE=	yes
USE_BZIP2=	yes

MAN1=		naim.1
MLINKS=		naim.1 nirc.1 naim.1 nicq.1 naim.1 nlily.1
PORTDOCS=	FAQ README commands.txt keyboard.txt

OPTIONS_DEFINE=	DETACH
DETACH_DESC=	Activate 'detach' feature (requires misc/screen)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--with-pkgdocdir=${DOCSDIR}
.else
CONFIGURE_ARGS+=	--without-pkgdocdir
.endif

.if ${PORT_OPTIONS:MDETACH}
RUN_DEPENDS=	screen:${PORTSDIR}/sysutils/screen
CONFIGURE_ARGS+=	--enable-detach
.endif

.include <bsd.port.mk>
