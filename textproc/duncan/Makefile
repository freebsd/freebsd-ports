# Created by: gurkan@phys.ethz.ch
# $FreeBSD$

PORTNAME=	duncan
PORTVERSION=	0.1
PORTREVISION=	3
CATEGORIES=	textproc gnustep
MASTER_SITES=	http://www.eskimo.com/~pburns/Dictionaries/files/ \
		${MASTER_SITE_GNUSTEP_CH}
DISTNAME=	Duncan-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	English to Thai dictionary for GNUstep

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/Duncan

post-patch:
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
