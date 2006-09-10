# New ports collection makefile for:    grouch
# Date created:         09 Sep 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	grouch
PORTVERSION=	20060713
CATEGORIES=	net-im
MASTER_SITES=	http://mail.rochester.edu/~asveikau/grouch/ \
		http://florida.ethz.ch/ports/distfiles/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	AOL and ICQ Instant Messenger client for GNUstep

BUILD_DEPENDS+=	${COMBOLIBDIR}/libRenaissance.so:${PORTSDIR}/${RENAISSANCE_PORT}
RUN_DEPENDS+=	${COMBOLIBDIR}/libRenaissance.so:${PORTSDIR}/${RENAISSANCE_PORT}

WRKSRC=		${WRKDIR}/Grouch
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile
RENAISSANCE_PORT?=	x11-toolkits/renaissance

.include <bsd.port.mk>
