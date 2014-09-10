# Created by: gurkan@phys.ethz.ch
# $FreeBSD$

PORTNAME=	timemon
PORTVERSION=	4.1
PORTREVISION=	2
CATEGORIES=	sysutils gnustep
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	gap
DISTNAME=	TimeMon-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CPU time usage monitor for GNUstep

NO_CDROM=	distribute without fee

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

post-patch:
	${RM} ${WRKSRC}/shared_obj/*.*

.include <bsd.port.mk>
