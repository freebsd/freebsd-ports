# New ports collection makefile for: naim
# Date created:			02 March 1999
# Whom:				mharo@area51.fremont.ca.us
#
# $FreeBSD$
#

PORTNAME=	naim
PORTVERSION=	0.11.5.9
CATEGORIES=	net
MASTER_SITES=	http://shell.n.ml.org/n/naim/

MAINTAINER=	rtdean@cytherianage.net
COMMENT=	Curses based AOL Instant Messager implementation

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--disable-nirc-manlink
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LIBTOOL=		yes

MAN1=		naim.1
MLINKS=		naim.1 nirc.1 naim.1 nicq.1 naim.1 nlily.1

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/naim.hlp ${DOCSDIR}
.endif

.include <bsd.port.mk>
