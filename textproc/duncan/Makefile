# Created by: gurkan@phys.ethz.ch
# $FreeBSD$

PORTNAME=	duncan
PORTVERSION=	0.1
PORTREVISION=	5
CATEGORIES=	textproc gnustep
MASTER_SITES=	http://www.eskimo.com/~pburns/Dictionaries/files/ \
		GNUSTEP_CH
DISTNAME=	Duncan-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	English to Thai dictionary for GNUstep

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/Duncan

post-patch:
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/Duncan.app/Duncan

.include <bsd.port.mk>
