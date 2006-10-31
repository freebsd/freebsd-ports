# New ports collection makefile for:    duncan
# Date created:         30 Oct 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	duncan
PORTVERSION=	0.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.eskimo.com/~pburns/Dictionaries/files/ \
		http://florida.ethz.ch/ports/distfiles/
DISTNAME=	Duncan-${PORTVERSION}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	English to Thai dictionary for GNUstep

WRKSRC=		${WRKDIR}/Duncan
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile

.include <bsd.port.mk>
