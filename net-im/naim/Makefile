# New ports collection makefile for: naim
# Date created:			02 March 1999
# Whom:				mharo@area51.fremont.ca.us
#
# $FreeBSD$
#

PORTNAME=	naim
PORTVERSION=	0.11.7.2
CATEGORIES=	net irc
MASTER_SITES=	http://shell.n.ml.org/n/naim/

MAINTAINER=	tlp@LiquidX.org
COMMENT=	Console ncurses-based AIM, ICQ, IRC, and Lily client

USE_BZIP2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-pkgdocdir=${DOCSDIR} \
			--mandir=${MANPREFIX}/man
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		naim.1
MLINKS=		naim.1 nirc.1 naim.1 nicq.1 naim.1 nlily.1

.if defined(WITH_DETACH)
BUILD_DEPENDS=	screen:${PORTSDIR}/misc/screen
RUN_DEPENDS=	screen:${PORTSDIR}/misc/screen

CONFIGURE_ARGS+=	--enable-detach
.endif

pre-fetch:
	@ ${ECHO} ""
	@ ${ECHO} "You can use the following build option(s):"
	@ ${ECHO} ""
	@ ${ECHO} "     WITH_DETACH=yes         Enables /detach (requires screen)"
	@ ${ECHO} ""

.include <bsd.port.mk>
