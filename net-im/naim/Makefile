# New ports collection makefile for: naim
# Date created:			02 March 1999
# Whom:				mharo@area51.fremont.ca.us
#
# $FreeBSD$
#

PORTNAME=	naim
PORTVERSION=	0.11.8.3.1
CATEGORIES=	net-im irc
MASTER_SITES=	http://naim.googlecode.com/files/

MAINTAINER=	j@scre.ws
COMMENT=	Console ncurses-based AIM, ICQ, IRC, and Lily client

GNU_CONFIGURE=	yes
USE_BZIP2=	yes

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		naim.1
MLINKS=		naim.1 nirc.1 naim.1 nicq.1 naim.1 nlily.1
PORTDOCS=	FAQ README commands.txt keyboard.txt

OPTIONS=	DETACH "Enable 'detach' feature (requires misc/screen)" off

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--with-pkgdocdir=${DOCSDIR}
.else
CONFIGURE_ARGS+=	--without-pkgdocdir
.endif

.if defined(WITH_DETACH)
RUN_DEPENDS=	screen:${PORTSDIR}/sysutils/screen
CONFIGURE_ARGS+=	--enable-detach
.endif

.include <bsd.port.post.mk>
